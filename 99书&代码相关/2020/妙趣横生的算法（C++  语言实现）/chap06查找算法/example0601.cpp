#include <iostream>
using namespace std;

template<class DataType>
DataType seqSearch(DataType[] key, int n, DataType k)
{
	for (int i = 0; i <= n; i++)
	{
		if (key[i] == k)  //�ӵ�һ����¼��ʼ�Ƚ�
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	int data[] = { 23, 65, 98, 45, 64, 25, 11 };
	cout <<seqSearch(data, 7, 98)<<endl;
	return 0;
}