// 使用冒泡排序将一组字符串按字母顺序排序 
#include <stdio.h>
#include <string.h>
#define MAX 50
void sorting(char arr[][MAX], int n)
{
	char t[20]; // 临时字符串
	int i, pass;

	for (pass = 0; pass <= n - 2;pass++)
	{
		for (i = 0; i <= n - 2; i++)
		{
			if (stricmp(arr[i], arr[i + 1]) > 0)
			{
				// 两个字符串互换
				strcpy(t, arr[i]);
				strcpy(arr[i], arr[i + 1]);
				strcpy(arr[i + 1], t);
			}
		}
	}
}

int main()
{
	char str[MAX][MAX];
	int i, n;

	printf("\nHow many strings? ");
	scanf("%d", &n);

	fflush(stdin);
	// 将字符串保存至二维字符类型数组中
	for (i = 0; i < n;i++)
	{
		printf("Enter string: ");
		gets(str[i]);
	}

	// 调用排序函数，传递了代表字符串数组和字符串个数的参数
	sorting(str, n);

	// 显示排序后的字符串
	printf("\nSorted strings:\n");
	for (i = 0; i < n; i++)
	{
		puts(str[i]);
	}
}