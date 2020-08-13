/*
将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。
如：输入“I am a student”，输出“tneduts a ma I”。
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
using namespace std;


void reserve_string(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reserve_all(char* str)
{
	char *cur = str;
	int len = strlen(str);
	reserve_string(str, str + len - 1);
	while (*cur)
	{

		char *start = cur;
		while ((*cur) != ' ' && (*cur) != '\0')
		{
			cur++;
		}
		reserve_string(start, cur - 1);
		while ((*cur) == ' ')
		{
			cur++;
		}
	}

}



int main()
{

	char sStr[100];
	//cin>>sStr;
	string s;
	getline(cin,s);   // lionel，最开始卡在这个地方了。主要是空格输入的问题
	sprintf(sStr,"%s",s.c_str());
	//reserve_all(sStr);
	//printf("%s\n",sStr);
	size_t i = strlen(sStr);//我用的是string对象中的 sStr.size()
	for (;i>0;i--)
	{
		cout<<sStr[i-1];
	}
	cout<<endl;


#if 0
	std::string s;
	while (cin >> s)
	//cin >> s;
	{

		for (size_t i = s.size();i>0;i--)
		{
			cout<<s[i-1]<<endl;
		}

#endif

#if 0
		std::string sRverse(s.rend(), s.rbegin());
		std::cout << sRverse << endl;

	}
#endif
	return 0;
}