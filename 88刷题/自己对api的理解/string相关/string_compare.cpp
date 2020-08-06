#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a="what";
    string b="what1";

    // 要直接跟0比较，不能用>0，之前用的>0的方式，不对。
    if(a.compare(b) == 0)
        cout<<"same"<<endl;
    else
        cout<<"don't same"<<endl;

    // 这种方式考虑得不全，会有负数的情况
    if(a.compare(b) > 0)
        cout<<" > 0; don't same"<<endl;
    else
        cout<<" > 0; same"<<endl;

    return 0;
}

// https://zh.cppreference.com/w/cpp/string/basic_string/compare  【不能只百度；还是要看手册】

// [C++之string的compare用法] https://www.cnblogs.com/cff2121/p/9989806.html


/*
don't same
 > 0; same
*/