// 有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？

#include <iostream>
using namespace std;

int add(int i)
{
	if (i == 1  || i == 2)
		return 1;
	else
		return add(i-2) + add(i-1);
}

int main()
{
	int iMonth = 0;
	int iCount = 0;
	while (cin >> iMonth)
	{
		iCount = add(iMonth);
	}
	return iCount;
}
