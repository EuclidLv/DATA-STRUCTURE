#ifndef headfunctions
#define headfunctions
typedef struct data_A {
	std::string name;
	int ID;
	float ChineseScore;
	float MathematicsScore;
	float EnglishScore;
};
typedef struct students_inf {
	data_A Data[100];
	int length;
};


int  mainMenu();
void ListInsert(students_inf*,std::istream&, int);
void totalScore(const students_inf&);
bool totalScoreFind(const students_inf&,int);
void printFunction(const data_A&);
void Find(const students_inf&);
int menu1(int&);
void sortList(students_inf&, int);
void swap(data_A&, data_A&);
void randomPer(const students_inf&, int);
void printList(const students_inf&);


#endif // !headfunctions#pragma once
