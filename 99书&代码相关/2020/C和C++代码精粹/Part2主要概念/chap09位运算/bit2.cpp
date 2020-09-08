// �����嵥9.2 ��λ�͸�λ������λ
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

	// ��������ÿһλ:
	for (int i = 0; i < NBITS;++i)
	{
		n |= (1u << i);
		cout << setw(NXDIGITS) << n << endl;
	}
	cout << endl;

	// ���ڹر����ǣ�
	for (int i = 0; i < NBITS; ++i)
	{
		n &= ~(1u << i);
		cout << setw(NXDIGITS) << n << endl;
	}
}