// date.h
// 程序清单11.3  Date类的定义
#if !defined(DATE_H)
#define DATE_H

#include <string>
#include <cassert>
using namespace std;

class Date
{
public:
	Date();
	Date(int y, int m, int d);

	// 存取器：
	void year(int);
	void month(int);
	void day(int);

	// 增变器
	int year() const;
	int month() const;
	int day() const;

	// 其它
	int compare(const Date&);
	operator string()const;
	static bool isleap(int);
	static int endOfMonth(int, int);
private:
	int year_;
	int month_;
	int day_;

	static int dtab[2][13];
};

inline Date::Date(int y, int m, int d)
{
	assert(1 <= m && m <= 12);
	assert(1 <= d && d <= endOfMonth(y, m));
	year_ = y;
	month_ = m;
	day_ = d;
}

inline int Date::year() const
{
	return year_;
}

inline int Date::month() const
{
	return month_;
}

inline int Date::day() const
{
	return day_;
}

inline void Date::year(int y)
{
	year_ = y;
}

inline void Date::month(int m)
{
	month_ = m;
}

inline void Date::day(int d)
{
	day_ = d;
}

inline bool Date::isleap(int y)
{
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

inline int Date::compare(const Date& r)
{
	int ydiff = year_ - r.year_;
	int mdiff = month_ - r.month_;
	return ydiff ? ydiff : (mdiff ? mdiff : day_ - r.day_);
}

inline int Date::endOfMonth(int y, int m)
{
	assert(1 <= m && m <= 12);
	return dtab[int(isleap(y))][m];
}
#endif