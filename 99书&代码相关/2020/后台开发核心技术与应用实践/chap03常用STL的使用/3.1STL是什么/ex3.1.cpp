#include<iostream>
#include <stdlib.h>

using namespace std;
#define max_size 10

//�Ƚ��������Ĵ�С
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;//<0������a<b
}

int main()
{
	int arr[max_size];
	int n = 0;
	//�ӱ�׼�����豸�ж���������ͬʱ�ۼ����������ֱ��������Ƿ���������Ϊֹ
	for (;;n++)
	{
		cin >> arr[n];
	}

	qsort(arr, n, sizeof(int), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}