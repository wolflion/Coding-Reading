// 程序清单9.2 置位和复位单独的位
// bit1.cpp
#include <iostream>
#include <iomanip>
#include <climits>  // <limits.h>
using namespace std;

int main()
{
	typedef unsigned short word;
	const size_t NBYTES = sizeof(word);
	const size_t NBITS = NBYTES * CHAR_BIT;
	const size_t NXDIGITS = NBYTES * 2;
	word n = 0;

	cout.setf(ios::hex, ios::basefield);
	cout.setf(ios::uppercase);
	cout.fill('0');

	// 依次设置每一位:
	for (int i = 0; i < NBITS;++i)
	{
		n |= (1u << i);
		cout << setw(NXDIGITS) << n << endl;
	}
	cout << endl;

	// 现在关闭它们：
	for (int i = 0; i < NBITS; ++i)
	{
		n &= ~(1u << i);
		cout << setw(NXDIGITS) << n << endl;
	}
}