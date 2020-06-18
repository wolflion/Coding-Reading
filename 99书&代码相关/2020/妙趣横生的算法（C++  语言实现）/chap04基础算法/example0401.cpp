/*
 * ��4.1���������������100��������Ƴ���ͳ�Ƹ�λ����0��1��2��3��4��5��6��7��8��9�����ֱַ��ж��٣�
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

#define MAX 101


//�������뺯��
void input(int num[])
{
	int i;
	srand((unsigned)time(NULL));  //�����������
	for (i = 1; i < MAX;i++)
	{
		num[i] = rand() % 100;  //����100���ڵ������
	}
}

//�������
void output(int num[])
{
	int i;
	for (i = 1; i < MAX;i++)
	{
		//cout << num[i] << endl;
		cout << num[i] << " ";
		if ( 0 == i%10)
		{
			cout << endl;
		}
	}
}

//ͳ����������
void cal_num(int num[], int count[])
{
	int i, mod;
	for (i = 0; i < MAX; i++)
	{
		mod = num[i] % 10; //��10��ģ���㣬�õ���λ����
		count[mod]++;
	}
}

//����������
int main()
{
	int num[MAX];
	int i, count[10];
	memset(count, 0, 10 * sizeof(int)); //��ʼ������
	input(num);
	cout << "100 num: " << endl;
	output(num);
	cal_num(num, count);
	for (i = 0; i < 10; i++)
	{
		cout << i << ":" << count[i] << endl;
	}
	return 0;
}