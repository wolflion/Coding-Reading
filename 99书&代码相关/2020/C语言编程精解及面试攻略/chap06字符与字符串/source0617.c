// 程序17：向函数传递一组字符串，并在函数内显示该字符串

#include <stdio.h>
#define MAX 50
void myfunction(char arr[MAX][MAX],int n)
{
	int i;
	for (i = 0; i < n;i++)
	{
		puts(arr[i]);
	}
}

int main()
{
	// 声明一个二维数组用来保存一组字符串
	char str[MAX][MAX];
	int i, n;

	printf("\nHow many strings? ");
	scanf("%i",&n);

	fflush(stdin);

	printf("\nEnter strings: \n");
	for (i = 0; i < n; i++)
	{
		gets(str[i]);
	}

	// 调用函数显示字符串
	printf("\nEntered strings are: \n");
	myfunction(str,n);
}