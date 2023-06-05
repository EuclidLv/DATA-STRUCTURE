#ifndef headfunctions
#define headfunctions

typedef struct student_inf
{
	std::string name;
	int ID;
	double ChineseScore;
	double MathematicsScore;
	double EnglishScore;
	student_inf* next;
};

int menu();
void ListInsert(student_inf*&, std::istream &, int);
void totalScore(const student_inf*);
bool totalScoreFind(const student_inf*, float); 
void printFunction(student_inf*);
void Find(const student_inf*);
int menu1(int&);
void sortList(student_inf*,int);
void swap(student_inf&,student_inf&);
void randomPer(const student_inf*, int);
void printList(const student_inf*);
#endif // !headfunctions

