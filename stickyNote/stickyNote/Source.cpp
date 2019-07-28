/*
This project was created to creat file carries user's name
so, The user can write notes inside it with the time it was written

Authers :
Amir ALtakroori and Faris Abu 3ram

Last modified: 7/23/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

/**
 void function prints a Main Menu as user's request which are four options:
 adding new user, adding new note, printing all notes and exit.
 There is no parameter passed to this function and there is no overloaded function.
*/
void printUserMenu()
{
	cout << "Welcome to the brand new Sticky Notes!\n\n"
		<< "Here is the list of operation this program offers : \n"
		<< " 1 - Add new user \n 2 - Add new note \n "
		<< "3 - View notes for a specific user \n 4 - Exit \n\n"
		<< "Please, enter your choice: ";
}

/**
 void function leads the user to main menu after pressing enter
 There is no parameter passed to this function and there is no overloaded function.
*/
void pressEnter()
{
	char Enter ;
	do
	{
		cout << "Press Enter to return to main menu : ";
		cin.get(Enter);
	}while(Enter!='\n');
}

/**
This class doesn't have data members. It just work as a functions collector
*/
class Password
{
public:

	/**
	Boolean function takes one string argument "User Name" and it asks the user to enter a password twice
	then the function will stored password and user in "UserName and Password" file
	*/
	bool checkWithAssigningPassword (string userName)
	{
		string userPassword , verifyPassword ;
		cin.get();
		cout << "Please enter your password: ";
		userPassword = hiddenInputLine(1);
		cout << "Please enter it again: ";
		verifyPassword = hiddenInputLine(2);

		if (userPassword == verifyPassword)
		{
			ofstream file;
			file.open("UserName and Password", ios_base::app); //ios_base::app use to overwrite the note into the file
			file << userName << endl << userPassword << endl;
			return true;
		}
		else
		{
			cout << "\nPassword and verification do not match!\n"
				<< "If you want to try again please press *1\n"
				<< "If you want to go back press *2 \n";

			int choice;		cin >> choice;
			if (choice == 1){
                    system("cls");
				return checkWithAssigningPassword (userName);
			}
			else
				return false;
		}
	}

	/**
	It take a full name as a string parameter and it return the user's passward as a string
	*/
	string getUserPassword(string fullNameUser)
	{
		ifstream inUserFile("UserName and Password");
		string storedUserName, storedPassword;
		while (getline(inUserFile,storedUserName))// we guarantee that there is userName and password already
			if (storedUserName == fullNameUser )
			{
				getline(inUserFile,storedPassword);
				return storedPassword;
			}
			return "";
	}

	/**
	That is a boolean function takes one string parameter which represent user name
	and it asks user to enter user's password. If the password correct it returns true
	*/
	bool askPassword(string userName,int n)
	{
		string enteredUserPassword ;
		system("cls");
		cout << "Please enter your password: ";
		cin.get();
		enteredUserPassword = hiddenInputLine(n);

		if (enteredUserPassword == getUserPassword (userName))
			return true;

		cout << "\nPassword is not correct!\n"
			<< "If you want to try again please press: 1\n"
			<< "If you want to go back press: 2 \n";

		char choice;		cin >> choice;
		if (choice == '1'){
                 system("cls");
			return askPassword (userName,1);
		}
		else
			return false;
	}

	/**
	This string returned function has no parameter. It will receive a hidden string from a user
	(It shows on the screen stars instead of entered character)
	*/
	string hiddenInputLine(int n)
	{
		char c;
		string hiddenInput="";
		string pass="";
        c = _getch();

		while (c!=13) /* ENTER KEY */
		{
			if(c==8){
                if(pass.size()==0){
                    hiddenInput="";
                    pass="";
                }
                else
                {
                hiddenInput.resize(hiddenInput.size()-1);
                pass.resize(pass.size()-1);
                cout<<pass;
                }
			}
			else{
                hiddenInput+=c;
				pass+="*";
				cout<<pass;

			}
			 c= _getch();
             system("cls");

            cout << "Please enter your password: ";
             if(n!=1)
                cout<<"\nPlease enter it again: ";


		}
		cout << endl;
		return hiddenInput;
	}

};

// This function will implement the first option in main menu
/**
	That is a void function doesn't have parameters. It receives two string which represent first and last name,
	then it generates a file have the same user's full name
*/
void addNewUser()
{
	/*
	This fuction let the user to add new user
	by entering first name and last name.
	Adding new user means open a new file in specific directory.
	Project guarantee that there is a unique user.
	*/

	cout << "\nWelcome aboard new user!\nPlease let me know your first name: ";
	string firstName;				cin >> firstName;

	cout << "Great " << firstName << ", now please enter your last name: ";
	string lastName;				cin >> lastName;

	string fullName = firstName + " " + lastName;
	if(fullName.find("?")!=string::npos||fullName.find("/")!=string::npos||fullName.find("\\")!=string::npos||fullName.find("|")!=string::npos||fullName.find("*")!=string::npos||fullName.find("<")!=string::npos||fullName.find(">")!=string::npos||fullName.find(":")!=string::npos||fullName.find("\"")!=string::npos)
         {
         cout<<"A file name can't contain any of the following characters :\n"
            <<"\\/:*?\"<>|\n";
            system("pause");

         }

     else{
	ifstream inUserFile (fullName);

	if (!inUserFile) // there is no file have the same user name
	{
	    system("cls");
		Password* userPasswoed = new Password();//pointer to class Password
		if (userPasswoed->checkWithAssigningPassword(fullName))  // to generate a password and to check if that proccess done
		{
			ofstream outUserFile (fullName); // just to open new file have the same name of user
			cout << fullName << " is added successfully\n";
		}
	}
	else // user name was used
		cout << "\n" << fullName << " was used!\n please try another name or write your notes directly!\n";
    }


}
/**
This class doesn't have data members. It just work as a functions collector
to add new note to the user's file by enter user's name and correct password
*/
class  Note
{
	// class to add new note
private:
	string note;//a note that user add it
	/**
	That is a void function have five parameters . It receives a year ,month ,day ,hour and minutes
	to return current date and time
*/
	void getTime(int& year, int& month, int& day, int& hour, int& mins)
	{
		// to claculate the current time

		time_t Time;//The time_t datatype is a data type in the ISO C library defined for storing system time values
		time(&Time);//Get the current calendar time as a value of type time_t.
		tm TM = *localtime(&Time);//Structure containing a calendar date and time broken down into its components.

		year = TM.tm_year + 1900;
		month = TM.tm_mon;
		day = TM.tm_mday;
		hour = TM.tm_hour;
		mins = TM.tm_min;
	}

public:
    /**
	That is a constructure have one parameters . It receives a string as note
	to create a new class  note
*/
	Note(string note)
	{
		//constructure was take note as  a parameters
		this->note = note;
	}
   /**
	That is a  function have no parameters . It  return current date , time and note of user as string
*/
	string toStringNote()
	{
		// to return a note and time  in best way
		int year, month, day, hour, mins;
		getTime(year, month, day, hour, mins);
		return (to_string(day) + '/' + to_string(month) + '/' + to_string(year) + " " + to_string(hour) + ':' + to_string(mins)  +':'+ "\n"+ note+'\n'+'\n' );
	}
};

// This function will implement the second option in main menu
/**
	That is a void function doesn't have parameters. It receives two string which represent first and last name,
	then it add new note for user inside his file
*/
void addNewNote(string fullNames)//"integer n"  to choose if you want to enter a new note in a the same file and "fullnames" the same file you want to add new note to it
{

	//user's full name
	cout << "Let's add a new note ... \n";
	cout << "Please let me know your first name: ";
	string firstName;				cin >> firstName;

	cout << "now please enter your last name: ";
	string lastName;				cin >> lastName;


	string fullName = firstName + " " + lastName ;

	ifstream file(fullName);
	if (!file)
	{
		cout << "Oh! Sorry the user name was not found, please check the name again and if this is your first time here,"
			<< "please go ahead and create a new user from the main menu ..." << endl;
			system("pause");
	}
	else
	{
	    char choice=2;
		Password* userPassword = new Password();//pointer to class Password
		if (userPassword -> askPassword(fullName,1))//if the password correct or not
		{
		    cout << "Your record is found,";
		    do{
			cout<<" I'm now opening your file,,,.\nReady!\nPlease enter your note ,when you finish enter \" stop \" in a single line :";
			string newNote,newnote="";
			getline(cin, newNote);
			if(newNote!="stop"){
                newnote+=newNote;
                newnote+="\n";
                while(newNote!="stop"){
                   newnote+=newNote;
			       newnote+="\n";
                   getline(cin, newNote);

			}
			}
			Note note(newnote);
			ofstream File;
			File.open(fullName, ios_base::app);//ios_base::app use to overwrite the note into the file
			File << note.toStringNote();
			File.close();
				cout << "If you want to add new note again please press: 1\n"
			<< "If you want to go back press: 2 \n";

				cin >> choice;

            system("cls");




			}while(choice=='1');
		}
	}

           system("cls");

}

// This function will implement the third option in main menu
/**
	That is a void function doesn't have parameters. It receives a string which represents user's full name
	and prints all note that has stored
*/
void printAllNotes()
{

	cout << "Retrieve your notes? Absolutely!";
	cout << "Please let me know your first name: ";
	string firstName;				cin >> firstName;

	cout << "now please enter your last name: ";
	string lastName;				cin >> lastName;

	string fullName = firstName + " " + lastName;
	ifstream inUserFile (fullName);

	if (!inUserFile) // there is no file have the same user name
		cout << "\n\n" << "User name: " << fullName << "was not found, please try diffrent user name!\n";


	else // user name was found
	{
		Password* userPassword = new Password();//pointer to class Password
		if (userPassword -> askPassword(fullName,1))//if the password correct or not
		{
		    system("cls");
			cout << "Found it!\n"
				<< "Here are your stored notes:\n"
				<< "-------------\n";

			string fileContents;
			while (getline(inUserFile,fileContents))
				cout << fileContents << endl;
			cout << "-------------\n"
				<< "Happy to serve you :)\n";
		}
	}
}

int main()
{
	char userChoice; // to control what is the option to user need to move it
	do
	{
		printUserMenu();
		system ("color 07");
		cin >> userChoice;
		switch (userChoice)
		{
		case '1':
			{
				/*
				This option let the user to add new user
				by entering first name and last name.
				Adding new user means open a new file in specific directory.
				Project guarantee that there is a unique user.
				*/
				system("cls");
				system("color 70");
				addNewUser();
				pressEnter();
			}
			break;
		case '2':
			{
				/*
				This option let the user to add new note
				by entering first name and last name.
				Adding new note means open a specific file depend on user name if exist or not .
				*/
				system("cls");
				system("color 70");
				addNewNote("");
				pressEnter();
			}
			break;
		case '3':
			{
				system("cls");
				system("color 70");
				printAllNotes();
				pressEnter();
			}
			break;
		case '4':
			break;
		default:
			{
				cout << "Invalid choice! \n";
				system("color 4");
				pressEnter();
			}
		}
		system("cls");
	} while (userChoice != '4');
	return 0;
}
