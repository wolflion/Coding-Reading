// date3.pp
// 程序清单7.8 Date类的实现
#include <stdio.h>
#include "date3.h"

const char *Date::month_text[13] =
{
	"Bad month", "January", "February", "March", "April",
	"May", "June", "July", "August", "September", "October",
	"November", "December"
};

Date::Date(int m, int d, int y) :month(m), day(d), year(y)
{
	// 用的还是 初始化列表的方式
}

char* Date::format(char* buf)const
{
	sprintf(buf, "%s %d, %d", month_text[dp->month], dp->day, dp->year);
	return buf;
}

int Date::compare(const Date& dp2) const 
{
	int result = year - dp2->year;
	if (result == 0)
		result = month - dp2->month;
	if (result == 0)
		result = day - dp2->day;
	return result;
}