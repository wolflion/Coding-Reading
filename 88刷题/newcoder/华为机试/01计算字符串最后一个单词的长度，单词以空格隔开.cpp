#include <string.h>
#include <stdio.h>

int GetLengthLastString(char* sContent)
{
	int i = strlen(sContent);
	int iLen = 0;
	for (int j = i-2; j >=0; --j) { // 问题1：这个地方边界条件，j>=0的时候，没有通过100%用例
		iLen++;
		if (sContent[j] == ' ') {// 问题2：最开始想用 != ' '，结果总是不对，于是想了一下，用break来跳出来
			iLen--;
			break;;
		}
	}
	return iLen;
}

int main()
{
    char str[100];
	fgets(str, sizeof(str), stdin);// fgets确实不知道，尤其刷题的时候输入函数； stdin这个搜了一下是用<stdio.h>，这个主要是unix环境用？
	int i = GetLengthLastString(str);
    printf("%d",i);
}

// 提交过的版本；--也是改了几稿，水平确实需要提高啊