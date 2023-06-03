#include <iostream>
#include <fstream>
#include "headfunction.h"
using namespace std;

int main()
{
	ifstream inFile;
	char filename[20]{};                      //this two part use to store a text name
	student_inf* L = nullptr;
	int p, num,score_find,choice;
	p = num =score_find= choice=0;            
	cout << "how many students are there in your class: ";
	cin >> num;                              //num is imporatant in the following part T(o) and S(o)
    again:
	p = menu();                              //print the main menu
	if (cin)
	{
		switch (p)
		{
		case 1:
		Choice:
			cout << "information comes form where ?\n";
			cout << "\t\t1. from your text.\n";
			cout << "\t\t2. from your keyboard.\n";                       //the three code use to ask the infmoration comes where
			cin >> choice;
			if (1 == choice)
			{
				cout << "Enter the name of data file: ";
				cin.get();
				cin.getline(filename, 20);
				inFile.open(filename);                                    //open file
				if (!inFile.is_open())                                    //if the file not open 
				{
					cout << " Could not open the file" << filename << endl;
					cout << "Programm terminating.\n";
					exit(EXIT_FAILURE);
				}
				ListInsert(L, inFile, num);                               //use file to insert list
			}
			else if (2 == choice)
				ListInsert(L,cin, num);                                   //use keyboard to insert list
			else
			{
				cout << "You've ENTERED bad input"; goto Choice;          //tell user entered a bad input and use goto to ask him re-enter
			}
			goto again; break;
		case 2:
			totalScore(L); goto again; break;
		case 3:
			cout << "你要查询多少分以上的学生的姓名： "; cin >> score_find;
			totalScoreFind(L,score_find); goto again; break;
		case 4:
			Find(L); goto again; break;
		case 5:
			sortList(L,num); goto again; break;
		case 6:
			randomPer(L,num); goto again; break;
		case 7:
			printList(L); goto again; break;
		default:
			cout << "You've ENTERED wrong number please re-enter: "; goto again; break;
		}
		}
	else
	{
		cout << "Bye!\n";
	}
	return 0;
}