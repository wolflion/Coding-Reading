//funtemp.cpp -- using a function template
#include <iostream>
using namespace std;
//function template prototype
template<typename T> //or <class T>
void Swap(T &a, T &b);


int main()
{
	int i = 10;
	int j = 20;
	cout << "i,j=" << i << "," << j << endl;
	cout << "Using compile-generated int swapper:\n";
	Swap(i, j);  //generates void Swap(int &, int &)
	cout << "Now i,j=" << i << "," << j << endl;


	double x = 24.5;
	double y = 81.7;
	cout << "x,y=" << x << "," << y << endl;
	cout << "Using compile-generated double swapper:\n";
	Swap(x, y);  //generates void Swap(double &, double &)
	cout << "Now x,y=" << x << "," << y << endl;
	cin.get();
	return 0;
}


//function template definition
template<typename T> // or <class T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}