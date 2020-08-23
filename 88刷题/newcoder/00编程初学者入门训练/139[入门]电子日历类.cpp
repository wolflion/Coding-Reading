/*
KiKi学习了面向对象技术，学会了通过封装属性（变量）和行为（函数）定义类，现在他要设计一个电子日历类TDate。
它有3个私有数据成员：Month,Day,Year和若干个公有成员函数，要求：
（1）带有默认形参值的构造函数，默认值为0, 0, 0；
（2）输出日期函数，用“日/月/年”格式输出日期；
（3）设置日期函数，从键盘输入年、月、日。

输入描述:
一行，三个整数，用空格分隔，分别表示年、月、日。
输出描述:
一行，用“日/月/年”格式输出日期。
*/

#include <iostream>
using namespace std;

class CDATE
{
public:
	CDATE(int month=0,int day=0,int year=0) 
		:m_month(month), m_day(day), m_year(year)
	{

	}

	void showDate(CDATE &date)
	{
		cout << date.m_day << "/" << date.m_month << "/" << date.m_year << endl;
	}

	void setDate(int year, int month, int day)
	{
		m_month = month;
		m_day = day;
		m_year = year;
	}
private:
	int m_month, m_day, m_year;
};

int main()
{
	int y, m, d;
	cin >> y >> m >> d;
	CDATE date;
	date.setDate(y, m, d);
	date.showDate(date);
	return 0;
}

/*
输入：2019 12 30
输出：30/12/2019
*/