//twotemps.cpp -- using overloaded template functions
#include <iostream>
using namespace std;

template <typename T>  //original template
void Swap(T &a, T &b);

template <typename T> // new template
void Swap(T *a, T *b, int n);   //lionel，这个地方自已写错了，写成&，其实应该是指针，传数组地址，导致link报错

void Show(int a[]);
const int Lim = 8;

int main()
{
	int i = 10,j = 20;
	cout << "i,j=" << i << "," << j << endl;
	cout << "Using compile-generated int swapper:\n";
	Swap(i, j);  //matches original template
	cout << "Now i,j=" << i << "," << j << endl;


	int d1[Lim] = { 0, 7, 0, 4, 1, 7, 7, 6 };
	int d2[Lim] = { 0, 7, 2, 0, 1, 9, 6, 9 };
	cout << "Original arrays:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);  // matches new template
	cout << "Swapped arrays:\n";
	Show(d1);
	Show(d2);
	cin.get(); //comment
	return 0;
}

template<typename T> 
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0; i < n;i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim;i++)
	{
		cout << a[i];
	}
	cout << endl;
}