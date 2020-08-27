// person.h
// 定义一个Person数据类型
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "date5.h"

using namespace std;

class ostream; //前置声明类
class Person
{
public:
	Person(const string& = "", const string &= "",
		const Date &= Date(0, 0, 0), const string &= "");
	bool operator=(const Person&)const;
	friend ostream& operator<<(ostream&, const Person&);
private:
	string last;
	string first;
	Date birth;
	string ssn;
};

#endif