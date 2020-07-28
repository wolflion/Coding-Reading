#include <iostream>
using namespace std;

struct TestStruct{
    TestStruct():name(__func__){}  // 构造函数的初始化列表
    const char* name;
};

int main()
{
    TestStruct ts;
    cout<<ts.name<<endl; //TestStruct
}


//g++ -std=c++11 2-1-3.cpp

