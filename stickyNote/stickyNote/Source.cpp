/*This project was created to creat file carries user's name
so, The user can write notes inside it with the time it was written
Authers :
Amir ALtakroori and Faris Abu 3ram
*/

#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
using namespace std;

void printUserMenu()
{
	cout << "Welcome to the brand new Sticky Notes!\n\n"
			 << "Here is the list of operation this program offers : \n"
			 << " 1 - Add new user \n 2 - Add new note \n "
			 << "3 - View notes for a specific user \n 4 - Exit \n\n"
			 << "Please, enter your choice: ";
}
void pressEnter()
{
    char Enter ;
    do
    {
            cout << "Press Enter to return to main menu : ";
            cin.ignore();
            cin.get(Enter);
            if(Enter=='\n')
                return;


<<<<<<< HEAD
void pressEnter()
{
    char Enter ;
    do
    {
            cout << "Press Enter to return to main menu : ";
            cin.ignore();
            cin.get(Enter);
            if(Enter=='\n')
                return;

=======
    }while(1);
}
// This function will implement the first option in main menu
void addNewUser()
{
	/*
				This fuction let the user to add new user
				by entering first name and last name.
				Adding new user means open a new file in specific directory.
				Project guarantee that there is a unique user.
				*/

				cout << "Welcome aboard new user!\nPlease let me know your first name: ";
				string firstName;				cin >> firstName;

				cout << "Great " << firstName << ", now please enter your last name: ";
				string lastName;				cin >> lastName;

				string fullName = firstName + "" + lastName;
				ifstream inUserFile (fullName);

				if (!inUserFile) // there is no file have the same user name
					ofstream outUserFile (fullName); // just to open new file have the same name of user
				else // user name was used
					cout << "\n\n" << fullName << " was used!\n please try another name or write your notes directly!\n";
>>>>>>> a37855ab820df2748893c469a5f7133d77c4eb87

    }while(1);
}

<<<<<<< HEAD
// This function will implement the first option in main menu
void addNewUser()
{
	/*
				This fuction let the user to add new user
				by entering first name and last name.
				Adding new user means open a new file in specific directory.
				Project guarantee that there is a unique user.
				*/

				cout << "Welcome aboard new user!\nPlease let me know your first name: ";
				string firstName;				cin >> firstName;

				cout << "Great " << firstName << ", now please enter your last name: ";
				string lastName;				cin >> lastName;

				string fullName = firstName + "" + lastName;
				ifstream inUserFile (fullName);

				if (!inUserFile) // there is no file have the same user name
					ofstream outUserFile (fullName); // just to open new file have the same name of user
				else // user name was used
					cout << "\n\n" << fullName << " was used!\n please try another name or write your notes directly!\n";

}

class  Note
{
        // class to add new note
    private:
        string note;//a note that user add it
        void getTime(int& year, int& month, int& day, int& hour, int& mins)
        {
                // to claculate the current time

                time_t Time;//The time_t datatype is a data type in the ISO C library defined for storing system time values
                time(&Time);//Get the current calendar time as a value of type time_t.
                tm TM = *localtime(&Time);//Structure containing a calendar date and time broken down into its components.
=======


class  Note
{
        // class to add new note
    private:
        string note;//a note that user add it
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
        Note() {}// default constructure
>>>>>>> a37855ab820df2748893c469a5f7133d77c4eb87

                year = TM.tm_year + 1900;
                month = TM.tm_mon;
                day = TM.tm_mday;
                hour = TM.tm_hour;
                mins = TM.tm_min;

<<<<<<< HEAD
        }

    public:
        Note() {}// default constructure


        Note(string note)
        {
                //constructure was take note as  a parameters
                this->note = note;
        }

        string toStringNote()
        {
                // to return a note and time  in best way
                int year, month, day, hour, mins;
                getTime(year, month, day, hour, mins);
                return (to_string(day) + '/' + to_string(month) + '/' + to_string(year) + " " + to_string(hour) + ':' + to_string(mins)  +':'+ "\n"+ note+'\n'+'\n' );
        }



};

void addNewNote()
{
                string firstName, lastName;//user's full name
                cout << "Let’s add a new note ... \n";
                cout << "Please enter your full name first:  "; cin >> firstName >> lastName;
                string fullName = firstName + lastName ;
                ifstream file(fullName);
                if (!file)
                {
                        cout << "Oh! Sorry the user name was not found, please check the name again and if this is your first time here, please go ahead and create a new user from the main menu ..." << endl;

                }
                else
                {

                        cout << "Your record is found, I’m now opening your file ….\nReady!\nPlease enter your note :";
                        string newNote;
                        cin.ignore();
                        getline(cin, newNote);
                        Note note(newNote);
                        ofstream File;
                        File.open(fullName, ios_base::app);//ios_base::app use to overwrite the note into the file
                        File << note.toStringNote();
                        File.close();


                }


}
=======
        Note(string note)
        {
                //constructure was take note as  a parameters
                this->note = note;
        }

        string toStringNote()
        {
                // to return a note and time  in best way
                int year, month, day, hour, mins;
                getTime(year, month, day, hour, mins);
                return (to_string(day) + '/' + to_string(month) + '/' + to_string(year) + " " + to_string(hour) + ':' + to_string(mins)  +':'+ "\n"+ note+'\n'+'\n' );
        }



};
void addNewNote()
{
                string firstName, lastName;//user's full name
                cout << "Let’s add a new note ... \n";
                cout << "Please enter your full name first:  "; cin >> firstName >> lastName;
                string fullName = firstName + lastName ;
                ifstream file(fullName);
                if (!file)
                {
                        cout << "Oh! Sorry the user name was not found, please check the name again and if this is your first time here, please go ahead and create a new user from the main menu ..." << endl;

                }
                else
                {

                        cout << "Your record is found, I’m now opening your file ….\nReady!\nPlease enter your note :";
                        string newNote;
                        cin.ignore();
                        getline(cin, newNote);
                        Note note(newNote);
                        ofstream File;
                        File.open(fullName, ios_base::app);//ios_base::app use to overwrite the note into the file
                        File << note.toStringNote();
                        File.close();


                }


}


>>>>>>> a37855ab820df2748893c469a5f7133d77c4eb87

int main()
{
	int userChoice; // to control what is the option to user need to move it
	do
	{
		printUserMenu();

		cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			{
				/*
				This option let the user to add new user
				by entering first name and last name.
				Adding new user means open a new file in specific directory.
				Project guarantee that there is a unique user.
				*/
				addNewUser();
				system("pause");

			}
			break;
		case 2:
			{
			    /*
				This option let the user to add new note
				by entering first name and last name.
				Adding new note means open a specific file depend on user name if exist or not .
				*/
				addNewNote();
				pressEnter();
<<<<<<< HEAD
=======



>>>>>>> a37855ab820df2748893c469a5f7133d77c4eb87
			}
			break;
		case 3:
			{

			}
			break;
		case 4:
			break;
		}

            system("cls");

	} while (userChoice != 4);

	return 0;
}