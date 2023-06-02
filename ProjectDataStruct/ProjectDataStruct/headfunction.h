#ifndef headfunctions
#define headfunctions

typedef struct student_inf
{
	char name[20];
	int ID;
	double ChineseScore;
	double MathematicsScore;
	double EnglishScore;
	student_inf* next;
};

int menu();
void ListInsert(student_inf*&, int);
void totalScore(const student_inf*);
bool totalScoreFind(const student_inf*, float); 

//find
 
//paixu

void random(const student_inf*, int);
void printList(const student_inf*);

#endif // !headfunctions

