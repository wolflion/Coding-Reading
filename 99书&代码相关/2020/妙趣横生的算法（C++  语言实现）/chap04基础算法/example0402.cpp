/*
 * 例4.2、统计随机给出的字符串中的数字的个数，字母个数及其它特殊字符的个数。
 */

#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1024

//统计函数
void cal_num(char *str, int count[])
{
	char *pstr;
	pstr = str;
	while (*pstr)
	{
		if (*pstr >= '0' && *pstr <= '9')
		{
			count[0]++;
		} 
		else if ((*pstr >= 'a'&&*pstr <= 'z') || (*pstr>='A'&&*pstr<='Z'))
		{
			count[1]++;
		}
		else
		{
			count[2]++;
		}
	}
}

//主函数
int main()
{
	char str[MAX];
	int i, count[3];//0->num；1->char；2->other
	memset(count, 0, 3 * sizeof(int));
	cout << "输入字符串：" << endl;
	//cin >> str;
	char c;
	(cin >> str).getchar(c);
	cal_num(str, count);
	for (i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			cout << "数字：" << count[i] << endl;
			break;
		case 1:
			cout << "字符：" << count[i] << endl;
			break;
		case 2:
			cout << "特殊字符：" << count[i] << endl;
			break;
		}
	}
	return 0;
}