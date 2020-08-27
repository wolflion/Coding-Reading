// date.cpp
// �����嵥11.4 Date���ʵ��

#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdio>
#include "date.h"
using namespace std;

// �������ඨ�������ʼ����̬��Ա��
int Date::dtab[2][13] =
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

Date::Date()
{
	// ��ý��������
	time_t tval = ::time(0);
	struct tm* tmp = ::localtime(&tval);

	month_ = tmp->tm_mon + 1;
	day_ = tmp->tm_mday;
	year_ = tmp->tm_year + 1900;
}

Date::operator string() const
{
	char buf[9];
	sprintf(buf,"%04d%02d%02d",year_,month_,day_);
	return string(buf);
}