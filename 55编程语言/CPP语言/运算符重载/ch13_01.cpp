//
// Created by lionel on 2020/5/5.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class Student
{
    friend int operator+(Student&, Student &);//非成员函数，调用private，声明为友元
private:
    int Score;
public:
    Student(int S_Score):Score(S_Score){}  //这是我改的，作者用的是{Score=S_Score;}的方式
};

int operator+(Student& a, Student& b)
{
    return a.Score+b.Score;
}

int main()
{
    Student x(90);
    Student y(75);
    cout<<"x+y="<<x+y<<endl;//x+y返回的是整型，所以无须重载<<
    return 0;
}