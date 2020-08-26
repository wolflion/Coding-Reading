/* tdate.c */
// 程序清单7.3 测试Date类型
#include <stdio.h>
#include "date.h"

#define DATELEN 19

int main()
{
	Date d1 = { 10, 1, 1951 }, d2 = { 3, 7, 1995 };
	char buf[DATELEN + 1]; // 这个加1，自己要记住
	int cmp;

	printf("d1 == %s\n", date_format(&d1, buf));
	printf("d2 == %s\n", date_format(&d2, buf));

	cmp = date_compare(&d1, &d2);

	printf("d1 %s d2\n", cmp<0 ? "precedes" : (cmp>0) ? "follow" : "equals");
	return 0;
}

/*输出：
root@raspberrypi:~/CodeStudy/202008# ./a.out
d1 == October 1, 1951
d2 == March 7, 1995
d1 precedes d2
*/

//直接在unix上，gcc date.c tdate.c date.h，生成了a.out执行文件