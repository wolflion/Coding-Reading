// tdate.cpp
// 程序清单11.5  测试Date类

#include <iostream>
#include "date.h"
using namespace std;

int main()
{
	Date d1, d2(1951, 10, 1);
	// tdate.cpp:11: error: no match for ‘operator<<’ in ‘std::operator<< [with _Traits = std::char_traits<char>](((std::basic_ostream<char, std::char_traits<char> >&)(& std::cout)), ((const char*)"d1==")) << d1’
	cout << "d1==" << d1 << endl;  // 问题是，d1是Date对象，无法转成string。
	cout << "d2==" << d2 << endl;
	cout << "d1.compare(d2): " << d1.compare(d2) << endl;
	cout << "d2.compare(d1): " << d2.compare(d1) << endl;
}

/*
g++ date.h date.cpp tdate.cpp
*/