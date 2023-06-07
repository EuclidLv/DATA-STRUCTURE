#include <iostream>
#include "headfuntions.h"
#include <random>
using namespace std;

int choice = 0;
int mainMenu()
{
    int p = 0;
    cout << "\t\t\t\t菜单\n";
    cout << "\t\t\t1. 信息输入\n";          //ListInsert
    cout << "\t\t\t2.总分统计\n";           //totalSore
    cout << "\t\t\t3.总分查询\n";           //totalScoreFind
    cout << "\t\t\t4.查询\n";               //Find
    cout << "\t\t\t5.排序\n";           //SortList
    cout << "\t\t\t6.随机抽人数\n";         //randomPer
    cout << "\t\t\t7.打印所输入表格\n";     //printList
    cout << "\t\t\t(q)to quit\n";
    cout << "\t\t请选择想要进行的项目： ";
    cin >> p;
    return p;
}


void ListInsert(students_inf* L, istream& os, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "this is # " << i + 1 << ": \n";
        cout << "student's name: ";
        os >> L->Data[i].name;
        cout << "stduent's ID: ";
        os >> L->Data[i].ID;
        cout << "student's Chinses score: ";
        os >> L->Data[i].ChineseScore;
        cout << "student's Mathematics score: ";
        os >> L->Data[i].MathematicsScore;
        cout << "student's Mathematics score: ";
        os >> L->Data[i].MathematicsScore;
        cout << "stdudents's English score: ";
        os >> L->Data[i].EnglishScore;
        count++;
    }
    L->length = count;
}

void totalScore(const students_inf&L)
{
    float sum = 0;
    int i = L.length;
    while (i != 0)
    {
        sum = (L.Data[i].ChineseScore) + (L.Data[i].MathematicsScore) + (L.Data[i].EnglishScore);
        cout << "Student's name:" << L.Data[i].name << "\t" << " ID: " << L.Data[i].ID << "\t\t" << "total score is: " << sum << endl;
        i--;
    }

}

int menu1(int& choice)
{
    cout << "\t\t\t1.按姓名\n";
    cout << "\t\t\t2.按学号\n";
    cout << "\t\t\t3.按语文成绩\n";
    cout << "\t\t\t4.按数学成绩\n";
    cout << "\t\t\t5.按英语成绩\n";
    cin >> choice;
    return choice;
}


bool totalScoreFind(const students_inf&L,int n )
{
    float sum = 0;
    int count = 0;
    int i = L.length;
    while (i != 0)
    {
        sum = (L.Data[i].ChineseScore) + (L.Data[i].MathematicsScore) + (L.Data[i].EnglishScore);
        if (sum >= n)
        {
            cout << "Student's name:" << L.Data[i].name << "\t" << " ID: " << L.Data[i].ID << "\t\t" << "total score is: " << sum << endl;
            count++;
        }
        i--;
    }
    if (0 == count)
        return false;
    else return true;
}


void Find(const students_inf&L)
{
    string name;
    int id = 0;
    int score = 0;
    int i = L.length;
    int count = 0;
    menu1(choice);
    switch (choice)
    {
    case 1:
        cout << "student's name: ";
        cin >> name;
        i = L.length;
        count = 0;
        while (i!=0)
        {
            if (name == L.Data[i].name)
            {
                printFunction(L.Data[i]);
                count++;
            }
            i--;
        }
        if (0==count)
        {
            cout << "not find such infmoration.\n";
        }break;
    case 2:
        cout << "student's ID: ";
        cin >> id;
        i = L.length;
        count = 0;
        while (i!=0)
        {
            if (0 == (id - (L.Data[i].ID)))
            {
                printFunction(L.Data[i]);
                count++;
            }
            i--;
        }
        if (0 == count)
        {
            cout << "not find such infmoration.\n";
        }break;
    case 3:
        cout << "student's Chinese score: ";
        cin >> score;
        i = L.length;
        count = 0;
        while (i != 0)
        {
            if (0 == (score - (L.Data[i].ChineseScore)))
            {
                printFunction(L.Data[i]);
                count++;
            }
            i--;
        }
        if (count == 0)
        {
            cout << "not find such infmoration.\n";
        }break;
    case 4:
        cout << "student's Mathematics score: ";
        cin >> score;
        i = L.length;
        count = 0;
        while (i != 0)
        {
            if (0 == (score - (L.Data[i].MathematicsScore)))
            {
                printFunction(L.Data[i]);
                count++;
            }
            i--;
        }
        if (count == 0)
        {
            cout << "not find such infmoration.\n";
        }break;
    case 5:
        cout << "student's English score: ";
        cin >> score;
        i = L.length;
        count = 0;
        while (i != 0)
        {
            if (0 == (score - (L.Data[i].EnglishScore)))
            {
                printFunction(L.Data[i]);
                count++;
            }
            i--;
        }
        if (count == 0)
        {
            cout << "not find such infmoration.\n";
        }break;
    default:
        cout << "You've ENTERED bad input";
    }
}


void printFunction(const data_A& p)
{
    cout << "name: " << p.name << "\t" << "ID: " << p.ID << endl;
    cout << "\t\t\tChinese score: " << p.ChineseScore << endl;
    cout << "\t\t\tMathematics score: " << p.MathematicsScore << endl;
    cout << "\t\t\tEnglish score: " << p.EnglishScore << endl;
}

void sortList(students_inf&L, int n)
{
    menu1(choice);
    switch (choice)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if ((L.Data[j].name) > (L.Data[j + 1].name))
                    swap(L.Data[j], L.Data[j + 1]);
            }
        }break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if ((L.Data[j].ID) > (L.Data[j + 1].ID))
                    swap(L.Data[j], L.Data[j + 1]);
            }
        }; break;
    case 3:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if ((L.Data[j].ChineseScore) > (L.Data[j + 1].ChineseScore))
                    swap(L.Data[j], L.Data[j + 1]);
            }
        }; break;
    case 4:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if ((L.Data[j].MathematicsScore) > (L.Data[j + 1].MathematicsScore))
                    swap(L.Data[j], L.Data[j + 1]);
            }
        }; break;
    case 5:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if ((L.Data[j].EnglishScore) > (L.Data[j + 1].EnglishScore))
                    swap(L.Data[j], L.Data[j + 1]);
            }
        }; break;
    default:
        cout << "You've ENTERED bad input";
    }
}

void swap(data_A& i , data_A& j)
{
    data_A temp;
    temp = i;
    i = j;
    j = i;
}

void randomPer(const students_inf&L, int n)
{
    int num = 0;
    const int MIN = 1;
    const int MAX = n;
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);
    cout << endl;
    num = distr(eng);
    int i = L.length;
    while (i != 0)
    {
        if (num == L.Data[i].ID)
        {
            cout << num << " . " << L.Data[i].name;
        }
        i--;
    }
}


void printList(const students_inf&L)
{
    int i = L.length;
    while (i != 0)
    {
        cout << " # " << i;
        printFunction(L.Data[i]);
        i--;
    }
}