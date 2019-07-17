#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include<string>
#include <ctime>


using namespace std;
string monthString[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };

void getTm(int& year, int& month, int& day, int& hour, int& mins)
{
	time_t tt;
	time(&tt);
	tm TM = *localtime(&tt);

	year = TM.tm_year + 1900;
	month = TM.tm_mon;
	day = TM.tm_mday;
	hour = TM.tm_hour;
	mins = TM.tm_min;

}


class  Note
{
private:
	string note;//a note that user add it

public:
	Note() {}
	Note(string note) {
		this->note = note;
	}

	string toStringNote() {
		int year, month, day, hour, mins;
		getTm(year, month, day, hour, mins);
		return (note + "\n" + to_string(day) + '/' + to_string(month) + '/' + to_string(year) + " " + to_string(hour) + ':' + to_string(mins) + ':');
	}





};
int main()
{


	int choice;// to control what is  the option to user need to move it 
	do
	{
		cout << "Welcome to the brand new “Sticky Notes”!\nHere is the list of operation this program offers : \n 1 - Add new user \n 2 - Add new note \n 3 - View notes for a specific user \n 4 - Exit \n ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{

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



	} while (choice != 4);








	system("pause");
	return 0;
}