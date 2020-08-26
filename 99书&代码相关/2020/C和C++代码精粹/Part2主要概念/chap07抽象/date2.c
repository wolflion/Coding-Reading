// date2.c
// 程序清单7.5 程序清单7.4的实现
#include <stdio.h>
#include <stdlib.h>
#include "date2.h"

struct Date
{
	int month;
	int day;
	int year;
};

static const char *month_text[] =
{
	"Bad month", "January", "February", "March", "April",
	"May", "June", "July", "August", "September", "October",
	"November", "December"
};

Date* date_create(int m, int d, int y)
{
	// 这个报错：date2.c:23:19: error: invalid conversion from ‘void*’ to ‘Date*’ [-fpermissive]
	// Date* dp = malloc(sizeof(Date));
	Date* dp = (Date*)malloc(sizeof(Date));  // 这是我改的
	if (dp == NULL)
	{
		return NULL;
	}
	dp->month = m;
	dp->day = d;
	dp->year = y;
	return dp;
}

char* date_format(const Date* dp, char* buf)
{
	sprintf(buf, "%s %d, %d", month_text[dp->month], dp->day, dp->year);
	return buf;
}

int date_compare(const Date* dp1, const Date* dp2)
{
	int result = dp1->year - dp2->year;
	if (result == 0)
		result = dp1->month - dp2->month;
	if (result == 0)
		result = dp1->day - dp2->day;
	return result;
}

void date_destroy(Date* dp)
{
	free(dp);
}