// 程序清单9.1 举例说明按位运算符
// bit1.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	typedef unsigned int word;
	typedef unsigned char byte;
	byte a = 0x55;
	byte b = 0xf0;

	cout.setf(ios::hex, ios::basefield);
	cout.setf(ios::uppercase);
	cout.fill('0');

	cout << "a|b==" << setw(2) << word(a | b) << endl;
	cout << "a&b==" << setw(2) << word(a & b) << endl;
	cout << "a^b==" << setw(2) << word(a ^ b) << endl;
	cout << "~a==" << setw(2) << word(byte(~a)) << endl;
	cout << "a<<1" << setw(2) << word(a<<1) << endl;
	cout << "b>>6" << setw(2) << word(a >>6) << endl;
}