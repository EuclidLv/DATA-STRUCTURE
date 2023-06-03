#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "headfunction.h"
using std::cout;
using std::cin;
using  std::endl;


//this is main menu
int menu()
{
    int p = 0;
    cout << "\t\t\t\t菜单\n";
    cout << "\t\t\t1. 信息输入\n";          //ListInsert
    cout << "\t\t\t2.总分统计\n";           //totalSore
    cout << "\t\t\t3.总分查询\n";           //totalScoreFind
    cout << "\t\t\t4.查询\n";               //Find
    cout << "\t\t\t5.分数排序\n";           //SortList
    cout << "\t\t\t6.随机抽人数\n";         //randomPer
    cout << "\t\t\t7.打印所输入表格\n";     //printList
    cout << "\t\t\t(q)to quit\n";
    cout << "\t\t请选择想要进行的项目： ";
    cin >> p;
    return p;
}


//the first and must done step to set up the LNode
void ListInsert(student_inf*& L, std::istream &os, int n)
{
    L = new student_inf;
    L->next = NULL;
    auto tail = L;
    for (int i = 0; i < n; i++)
    {
        student_inf* p = new student_inf;
        cout << "this is # " << i + 1 << ": \n";
        cout << "student's name: ";
        os >> p->name;
        cout << "stduent's ID: ";
        os >> p->ID;
        cout << "student's Chinses score: ";
        os >> p->ChineseScore;
        cout << "student's Mathematice score: ";
        os >> p->MathematicsScore;
        cout << "student's English score: ";
        os>> p->EnglishScore;
        tail->next = p;
        tail = p;
        p->next = NULL;
    }
}


//caculate the total score
void totalScore(const student_inf* L)
{
    float sum = 0;
    auto p = L->next;
    while (p!=NULL)
    {
        sum = (p->ChineseScore) + (p->MathematicsScore) + (p->EnglishScore);
        cout << "Student's name:" << p->name << "\t" << " ID: " << p->ID << "\t\t" << "total score is: " << sum << endl;
        p = p->next;
    }
}

//user input the total score to find a student whose total score matches the input
bool totalScoreFind(const student_inf* L ,float n)
{
    float sum = 0;
    int count = 0;
    auto p = L->next;
    while (p != NULL)
    {
        sum = float(p->ChineseScore) + float(p->MathematicsScore) + float(p->EnglishScore);
        if (sum >= n)
        {
            cout << "student's name is: " << p->name << "\t\ttotal score is: " << sum << endl;
            count++;
        }
        p = p->next;
    }
    if (0 == count)
        return false;
    else return true;
}


//this menu is works for the find and sort part
int menu1()
{
    int choice = 0;
    cout << "\t\t\t1.按姓名\n";
    cout << "\t\t\t2.按学号\n";
    cout << "\t\t\t3.按语文成绩\n";
    cout << "\t\t\t4.按数学成绩\n";
    cout << "\t\t\t5.按英语成绩\n";
    cin >> choice;
    return choice;
}


//find part
void Find(const student_inf* L)
{
    auto p = L->next;
    int choice = 0; 
    char name[20]{};
    int id = 0;
    int score = 0;
    choice = menu1();
    switch (choice)
    {
    case 1:
        cout << "student's name: ";
        cin >> name;
        while (p != NULL)
        {
            if (!strcmp(name, p->name))
            {
                printFunction(p);
            }
            p = p->next;
        }
        if (p == NULL)
        {
            cout << "not find such infmoration.\n";
        }break;
    case 2:
        cout << "student's ID: ";
        cin >> id;
        while (p != NULL)
        {
            if (0 == (id - (p->ID)))
            {
                printFunction(p);
            }
            p = p->next;
        }
        if (p == NULL)
        {
            cout << "not find such infmoration.\n";
        }break;
    case 3:
        cout << "student's Chinese score: ";
        cin >> score;
        while (p != NULL)
        {
            if (0 == (score - (p->ChineseScore)))
            {
                printFunction(p);
            }
            p = p->next;
        }
        if (p == NULL)
        {
            cout << "not find such infmoration.\n";
        }break;
    case 4:
        cout << "student's Mathematics score: ";
        cin >> score;
        while (p != NULL)
        {
            if (0 == (score - (p->MathematicsScore)))
            {
                printFunction(p);
            }
            p = p->next;
        }
        if (p == NULL)
        {
            cout << "not find such infmoration.\n";
        }break;
    case 5:
        cout << "student's English score: ";
        cin >> score;
        while (p != NULL)
        {
            if (0 == (score - (p->EnglishScore)))
            {
                printFunction(p);
            }
            p = p->next;
        }
        if (p == NULL)
        {
            cout << "not find such infmoration.\n";
        }break;
    default:
        cout << "You've ENTERED bad input";
    }
}

void printFunction(student_inf* p)
{
    cout << "name: " << p->name << "\t" << "ID: " << p->ID << endl;
    cout << "\t\t\tChinese score: " << p->ChineseScore << endl;
    cout << "\t\t\t Mathematics score: " << p->MathematicsScore << endl;
    cout << "\t\t\tEnglish score: " << p->EnglishScore << endl;
}

//sort part
void sortList(student_inf*& L,int n)
{
    student_inf* p = L->next;
    student_inf* nextt = p;
    int choice = 0;
    choice = menu1();
    switch (choice)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            p = (p + i);
            while (nextt != NULL)
            {
                if (int(strcmp(p->name, nextt->name)) >= 0)
                {
                    swap(*p, *nextt);
                    nextt = nextt->next;
                }
                else
                {
                    nextt = nextt->next;
                }
            };
        }break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            p = (p + i);
           
            while (nextt != NULL)
            {
                if ((p->ID) - (nextt->ID) >= 0)
                {
                    swap(*p, *nextt);
                    nextt = nextt->next;
                }
                else
                {
                    nextt = nextt->next;
                }
            }
        }; break;
    case 3:
        for (int i = 0; i < n; i++)
        {
            p = L->next;
           while(p->next!=NULL||p!=NULL)
            {   
                if ((p->ChineseScore) > ((p->next)->ChineseScore))
                    swap(*p, *p->next);
                p = p->next;
            }
        }
       ; break;
    case 4:
        for (int i = 0; i < n; i++)
        {
            p = (p + i);
            while (nextt != NULL)
            {
                if ((p->MathematicsScore) - (nextt->MathematicsScore) >= 0)
                {
                    swap(*p, *nextt);
                    nextt = nextt->next->next;
                }
                else
                {
                    nextt = nextt->next;
                }
            }
        }; break;
    case 5:
        for (int i = 0; i < n; i++)
        {
            p = (p + i);
            while (nextt != NULL)
            {
                if ((p->EnglishScore) - (nextt->EnglishScore) >= 0)
                {
                    swap(*p, *nextt);
                    nextt = nextt->next->next;
                }
                else
                {
                    nextt = nextt->next;
                }
            }; break;
        }
    default:
        cout << "You've ENTERED bad input";
    }
}


//swap works for the sort part
void swap(student_inf& p, student_inf& next)
{
    student_inf temp;
    temp = p;
    p = next;
    next = temp;
}



 

//to find a students randomly
void randomPer(const student_inf* L, int n)
{
    int num = 0;
    const int MIN = 1;
    const int MAX = n;
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);
    cout << endl;
     num = distr(eng);
    auto p = L->next;
    while (p != NULL)
    {
        if (num == p->ID)
        {
            cout << num << " . " << p->name;
        }
        p = p->next;
    }

}


//to show your LNode
void printList(const student_inf* L)
{
    int i = 1;
    student_inf* p = L ->next;
    while (p != NULL)
    {
        cout << " # " << i;
        printFunction(p);
        i++;
        p = p->next;
    }
}

