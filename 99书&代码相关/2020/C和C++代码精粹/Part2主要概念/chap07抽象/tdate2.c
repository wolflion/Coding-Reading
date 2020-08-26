/* tdate2.c */
// 程序清单7.6 测试新的Date类型
#include <stdio.h>
#include "date2.h"

#define DATELEN 19

int main()
{
	Date *d1 = date_create(10, 1, 1951), *d2 = date_create(3, 7, 1995);
	char buf[DATELEN + 1];
	int cmp;

	printf("d1 == %s\n", date_format(d1, buf));
	printf("d2 == %s\n", date_format(d2, buf));

	cmp = date_compare(d1, d2);

	printf("d1 %s d2\n", cmp<0 ? "precedes" : (cmp>0) ? "follow" : "equals");
	date_destroy(d1);
	date_destroy(d2);
	return 0;
}


/*
g++ date2.h date2.c tdate2.c
没有编译成功
tdate2.c:10:2: error: ‘Date’ was not declared in this scope
*/

