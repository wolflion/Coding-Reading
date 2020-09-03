// 20200903，敲的f33例子，自己也没太看懂，搜了一下，应该是堆的构建过程，后面学好DS了再来看一下

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>
using namespace std;

void Sift(int a[], int i, int h)
{
	int j, temp = a[i];
	j = 2 * i + 1;
	while (i <= h)
	{
		if (j < h && a[j] < a[j + 1])
			j++;
		if (temp>=a[j])
		{
			break;
		}
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
	}
	a[i] = temp;
}

void f33(int a[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)
		Sift(a, i, n - 1);
}

int main()
{
	int i, a[10] = { 10, 20, 5, 23, 25, 62, 21, 1, 32, 9 };
	f33(a, 10);
	for ( i = 0; i < 10; i++)
	{
		cout << a[i] << "=";
	}
	cout << endl;
	return 0;
}