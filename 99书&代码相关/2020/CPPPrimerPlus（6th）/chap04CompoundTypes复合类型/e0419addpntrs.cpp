// addpntrs.cpp -- pointer addition
#include <iostream>
using namespace std;

int main()
{
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };

	//Here are two ways to get the address of an array
	double *pw = wages; //name of an array = address
	short *ps = &stacks[0]; // or use address operator
	//with array element

	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
}