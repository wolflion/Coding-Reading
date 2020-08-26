/*
题目描述
输入3科成绩，然后把三科成绩输出，成绩为整数形式。
输入描述:
一行，3科成绩，用空格分隔，范围（0~100）。
输出描述:
一行，把3科成绩显示出来，输出格式详见输出样例。
示例1
输入
复制
60 80 90
输出
复制
score1=60,score2=80,score3=90
*/


#include <iostream>
using namespace std;

int main()
{
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;         // 问题是：如何用c语言的屏幕输入？

	typedef struct 
	{
		int score1;
		int score2;
		int score3;
	}score;

	score scoreValue;
	scoreValue.score1 = s1;
	scoreValue.score2 = s2;
	scoreValue.score3 = s3;
	
	printf("score1=%d,score2=%d,score3=%d\n", scoreValue.score1, scoreValue.score2, scoreValue.score3);
	return 0;
}