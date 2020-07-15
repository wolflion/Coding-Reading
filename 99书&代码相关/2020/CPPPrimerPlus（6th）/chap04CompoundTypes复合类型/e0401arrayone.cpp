// arrayone.cpp -- small arrays of integers

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int yams[3]; // creates array with three elements
	yams[0] = 7; // assign value to first element
	yams[1] = 8;
	yams[2] = 6;

	int yamcost[3] = { 20, 30, 5 }; // create, initialize array

	//NOTE: If your C++ compiler or translator can't initialize
	// that array, use static int yamcosts[3] instead of 
	// int yamcosts[3]

	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The packages with " << yams[1] << " yams costs ";
	cout << yamcost[1] << " cents per yam.\n";
	int total = yams[0] * yamcost[0] + yams[1] * yamcost[1];
	total = total + yams[2] * yamcost[2];
	cout << "The total yam expense is " << total << " cents.\n ";

	cout << "\nSize of yams array = " << sizeof yams;  //sizeof(yams)，**sizeof是优先级排第二的单目运算符**。
	cout << "bytes.\n";
	cout << "Size of one element = " << sizeof yams[0];
	cout << " bytes.\n";
	getchar();
	return 0;
}