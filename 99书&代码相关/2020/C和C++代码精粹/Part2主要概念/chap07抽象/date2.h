//date2.h
// 程序清单7.4 一个较安全的Date类型（从某种程度上说）

#ifdef DATE2_H
#define  DATE2_H

// 声明不完全的日期类型
typedef struct Date Date;
Date *date_create(int, int, int);
char* date_format(const Date*, char*);
int date_compare(const Date*, const Date*);
void date_destroy(Date*);

#endif