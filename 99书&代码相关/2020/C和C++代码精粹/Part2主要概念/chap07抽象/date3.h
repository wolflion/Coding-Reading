//date3.h
// 程序清单7.7 C++形式的Date类型

#ifdef DATE3_H
#define  DATE3_H

struct Date
{
	Date(int, int, int);
	char* format(char*) const;
	int compare(const Date&)const;

private:
	int month;
	int day;
	int year;

	static const char* month_text[13];
};

#endif