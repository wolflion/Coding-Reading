/* tdate3.cpp */
// 程序清单7.9 举例说明Date类
#include<iostream>
#include "date3.h"

int main()
{
	const size_t DATELEN 19;  // 都不用define了
	char buf[DATELEN + 1];

	Date d1(10, 1, 1951), d2(3, 7, 1995);
	cout << "d1 == " << d1.format(buf) << endl;
	cout << "d2 == " << d2.format(buf) << endl;

	int cmp = d1.compare(d2);
	cout << "d1 " << (cmp<0 ? "precedes" : (cmp>0) ? "follow" : "equals") << " d2\n";

	return 0;
}


/*
g++ date2.h date2.c tdate2.c
没有编译成功
tdate2.c:10:2: error: ‘Date’ was not declared in this scope
*/

