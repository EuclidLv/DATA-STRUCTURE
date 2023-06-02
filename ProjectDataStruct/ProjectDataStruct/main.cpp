#include <iostream>
#include "headfunction.h"
using namespace std;

int main()
{
	student_inf* L=NULL;
	int p, num,score_find;
	p = num =score_find= 0;
	cout << "how many students are there in your class: ";
	cin >> num;
    again:
	p = menu();
	if (cin)
	{
		switch (p)
		{
		case 1:
            ListInsert(L,num); goto again; break;
		case 2:
			totalScore(L); goto again; break;
		case 3:
			cout << "你要查询多少分以上的学生的姓名： "; cin >> score_find;
			totalScoreFind(L,score_find); goto again; break;
		case 4:
			; goto again; break;
		case 5:
			; goto again; break;
		case 6:
			random(L,num); goto again; break;
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