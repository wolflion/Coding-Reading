#include <iostream>
using namespace std;
#include "05Array.h"

int main()
{
	Array a1(10);
	for (int i = 0; i < a1.length();i++)
	{
		a1.setData(i, i);
	}

	for (int i = 0; i < a1.length();i++)
	{
		printf("array %d:%d\n", i, a1.getData(i));
	}

	Array a2=a1;

	for (int i = 0; i < a2.length(); i++)
	{
		printf("array %d:%d\n", i, a2.getData(i));
	}

	cin.get();
	//system("pause");
	return 0;
}

//不写后面的实现，链接就找不到；---lionel 20200711

Array::Array(int length)
{

}
Array::Array(const Array &obj)
{

}
int Array::length()
{
	return 0;
}
void Array::setData(int index, int value)
{

}
int Array::getData(int index)
{
	return 0;
}

Array::~Array()
{

}