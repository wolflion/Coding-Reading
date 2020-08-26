/* date.h  */
// 程序清单7.1 C形式的日期类型
#ifndef DATE_H
#define DATE_H

struct Date
{
	int month;
	int day;
	int year;
};

typedef struct Date Date; // 在C++中不需要
char *date_format(const Date*, char*);
int date_compare(const Date*, const Date*);
#endif