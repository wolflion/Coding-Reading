/*
https://www.nowcoder.com/practice/a35ce98431874e3a820dbe4b2d0508b1?tpId=37&&tqId=21225&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

输入描述:
第一行输入一个有字母和数字以及空格组成的字符串，第二行输入一个字符。

输出描述:
输出输入字符串中含有该字符的个数。

输入
ABCDEF
A
输出
1

*/


#include <string.h>
#include <stdio.h>

int GetCharCount(char* s, char c)
{
	char c1 = -1;
	char c2 = -1;
	int iCount = 0;
	if (65 <= c <=90)
	{
		c1 = c + 32;
	}

	if (97 <= c <=122)
	{
		c2 = c - 32;
	}

	for (int i = 0; i < strlen(s);i++)
	if (s[i] == c1 || s[i] == c2 || s[i] == c)
	{
		iCount++;
	}
	return iCount;
}

int main()
{
	char str[1000];
	//fgets(str, sizeof(str), stdin);
	//cin.getline(str, 10000);
	gets(str);
	char c = getchar();
	int i = GetCharCount(str, c);
	printf("%d", i);
}
