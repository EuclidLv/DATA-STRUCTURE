#include <iostream>
#include <random>
using std::cout;
using std::cin;
#include "headfunction.h"

int menu()
{
    int p = 0;
    cout << "\t\t\t\t菜单\n";
    cout << "\t\t\t1. 信息输入\n";          //ListInsert
    cout << "\t\t\t2.总分统计\n";           //totalSore
    cout << "\t\t\t3.总分查询\n";           //totalScoreFind
    cout << "\t\t\t4.查询\n";         //stop
    cout << "\t\t\t5.分数排序\n";
    cout << "\t\t\t6.随机抽人数\n";
    cout << "\t\t\t7.打印所输入表格\n";
    cout << "\t\t\t(q)to quit\n";
    cout << "\t\t请选择想要进行的项目： ";
    cin >> p;
    return p;
}

void ListInsert(student_inf*&L, int n)
{
    L = new student_inf;
    L->next = NULL;
    auto tail = L;
    for (int i = 0; i < n; i++)
    {
        student_inf* p = new student_inf;
        cout << "this is # " << i + 1 << ": \n";
        cout << "student's name: ";
        cin >> p->name;
        cout << "stduent's ID: ";
        cin >> p->ID;
        cout << "student's Chinses score: ";
        cin >> p->ChineseScore;
        cout << "student's Mathematice score: ";
        cin >> p->MathematicsScore;
        cout << "student's English score: ";
        cin >> p->EnglishScore;
        tail->next = p;
        tail = p;
        p->next = NULL;
    }
}

void totalScore(const student_inf* L)
{
    float sum = 0;
    auto p = L->next;
    while (p!=NULL)
    {
        sum = (p->ChineseScore) + (p->MathematicsScore) + (p->EnglishScore);
        cout << "Student's name:" << p->name << "\t" << " ID: " << p->ID << "\t\t" << "total score is: " << sum;
        p = p->next;
    }
}

bool totalScoreFind(const student_inf* L ,float n)
{
    float sum = 0;
    int count = 0;
    auto p = L + 1;
    while (p != NULL)
    {
        sum = float(p->ChineseScore) + float(p->MathematicsScore) + float(p->EnglishScore);
        if (sum >= n)
        {
            cout << "student's name is: " << p->name << "\t\ttotal score is: " << sum;
            count++;
        }
    }
    if (0 == count)
        return false;
    else return true;
}

//find
//paixu

void random(const student_inf* L, int n)
{
    const int MIN = 1;
    const int MAX = n;
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);
    cout << distr(eng);

}
void printList(const student_inf* L)
{
    int i = 1;
    auto p = L + 1;
    while (p != NULL)
    {
        cout << " # " << i;
        cout << "name: " << p->name << "\t\t"
            << "ID: " << p->ID;
        cout << "Chinese score: " << p->ChineseScore << "\t\t" << "Mathematics score: " << p->MathematicsScore
            << "\t\t" << "English score: " << p->EnglishScore;
        i++;
        p = p->next;
    }
}

