#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printUserMenu()
{
	cout << "Welcome to the brand new Sticky Notes!\n\n"
			 << "Here is the list of operation this program offers : \n"
			 << " 1 - Add new user \n 2 - Add new note \n "
			 << "3 - View notes for a specific user \n 4 - Exit \n\n"
			 << "Please, enter your choice: ";
}

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

				cout << "Welcome aboard new user!\nPlease let me know your first name: ";
				string firstName;				cin >> firstName;

				cout << "Great " << firstName << ", now please enter your last name: ";
				string lastName;				cin >> lastName;

				string fullName = firstName + " " + lastName; 
				ifstream inUserFile (fullName);

				if (!inUserFile) // there is no file have the same user name
					ofstream outUserFile (fullName); // just to open new file have the same name of user
				else // user name was used
					cout << "\n\n" << fullName << " was used!\n please try another name or write your notes directly!\n";

				system("pause");
				system("cls");
			}
			break;
		case 2:
			{

			}
			break;
		case 3:
			{

			}
			break;
		case 4:
			break;
		}



	} while (userChoice != 4);

	return 0;
}