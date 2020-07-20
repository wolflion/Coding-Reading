// protos.cpp -- using prototypes and function calls
#include <iostream>
using namespace std;

void cheers(int);  // prototype: no return value
double cube(double x);  // prototype: returns a double

int main()
{
	cheers(5);// function call
	cout << "Give me a number: ";
	double side;
	cin >> side;
	double volume = cube(side);  // function call
	cout << "A " << side << "-foot cube has a volume of ";
	cout << volume << " cubic fee.\n";
	cheers(cube(2));  // prototype protection at work
	cin.get();
	return 0;
}

void cheers(int n)
{
	for (int i = 0; i < n;i++)
	{
		cout << "Cheers! ";
	}
	cout << endl;
}

double cube(double x)
{
	return x*x*x;
}