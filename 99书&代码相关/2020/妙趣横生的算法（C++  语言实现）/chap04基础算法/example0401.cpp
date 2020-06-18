/*
 * 例4.1、用随机函数生成100个数，设计程序统计个位上是0，1，2，3，4，5，6，7，8，9的数字分别有多少？
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

#define MAX 101


//处理输入函数
void input(int num[])
{
	int i;
	srand((unsigned)time(NULL));  //设置随机种子
	for (i = 1; i < MAX;i++)
	{
		num[i] = rand() % 100;  //生成100以内的随机数
	}
}

//输出函数
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

//统计字数个数
void cal_num(int num[], int count[])
{
	int i, mod;
	for (i = 0; i < MAX; i++)
	{
		mod = num[i] % 10; //对10求模运算，得到个位数字
		count[mod]++;
	}
}

//测试主函数
int main()
{
	int num[MAX];
	int i, count[10];
	memset(count, 0, 10 * sizeof(int)); //初始化数组
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