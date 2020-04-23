//
// Created by lionel on 2020/4/24.
//

#include <iostream>
using namespace std;

class Base
{
public:
    static int var;
};

int Base::var = 10;

class Derived:public Base
{

};

int main()
{
    Base base1;
    base1.var++;  //11
    cout<<base1.var<<endl;
    Base base2;
    base2.var++;//12
    cout<<base2.var<<endl;
    Derived derived1;
    derived1.var++;//13
    cout<<derived1.var<<endl;
    Base::var++;//14
    cout<<derived1.var<<endl;
    return 0;
}



