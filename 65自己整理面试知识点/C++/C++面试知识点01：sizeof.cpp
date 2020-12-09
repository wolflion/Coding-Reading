#include <iostream>
using namespace std;

struct sA
{
	char cA;
	int iA;
	double dA;
};


int main()
{
	cout << sizeof(int) << endl;   // 4
	cout << sizeof(unsigned short) << endl;  // 2
	cout << sizeof(double) << endl;  // 8
	cout << sizeof(sA) << endl;  //16
}