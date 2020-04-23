//
// Created by lionel on 2020/4/24.
//

#include <iostream>
#include <string>
using namespace std;

class Box
{
public:
    Box(int, int , int);
    virtual void display();

protected:
    int length,height,width;  //受保护成员，派生类可以访问
};

//类体外定义 Box::不可少
Box::Box(int l, int h, int w)  //是不是应该用初始化列表的方式？ lionel
{
    length = l;
    height = h;
    width = w;
}

void Box::display()
{
    cout<<"length:"<<length<<endl;
    cout<<"height:"<<height<<endl;
    cout<<"width:"<<width<<endl;
}

class FilledBox:public Box
{
public:
    FilledBox(int ,int ,int ,int ,string);
    virtual void display();

private:
    int weight;
    string fruit;//装的啥水果
};

void FilledBox::display()
{
    cout<<"length:"<<length<<endl;
    cout<<"height:"<<height<<endl;
    cout<<"width:"<<width<<endl;
    cout<<"weight:"<<weight<<endl;
    cout<<"fruit:"<<fruit<<endl;
}

FilledBox::FilledBox(int l, int h, int w, int we, string f):Box(l,h,w),weight(w),fruit(f)
{

}

int main()
{
    Box box(1,2,3);
    FilledBox fbox(2,3,4,5,"apple");
    Box *pt = &box;
    pt->display();
    pt = &fbox;
    pt->display();
    return  0;
}


/*
length:1
height:2
width:3
length:2
height:3
width:4
weight:4
fruit:apple
 */