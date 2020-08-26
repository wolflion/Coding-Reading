/* date.c */
// 程序清单7.2 Date类型的实现
#include <stdio.h>
#include "date.h"

static const char *month_text[] =
{
	"Bad month", "January", "February", "March", "April",
	"May", "June", "July", "August", "September", "October",
	"November", "December"
};

char *date_format(const Date* dp, char* buf)
{
	// 格式化输出
	sprintf(buf, "%s %d, %d", month_text[dp->month], dp->day, dp->year);
	return buf;
}

int date_compare(const Date* dp1, const Date* dp2)
{
	int result = dp1->year - dp2->year;
	if (return == 0)
	//{  // 加不加 {的区别在哪？
		result = dp1->month - dp2->month;
	//}
	if (result == 0)
	//{
		result = dp1->day - dp2->day;
	//}
	return result;
}