// scope2.c 举例说明函数和文件作用域
// 程序清单11.2 说明函数和文件作用域
#include <stdio.h>

int main()
{
	void f1(int);
	void f2(void);

	f1(23);
	f2();
	getchar();
	return 0;
}

int i = 13;
void f1(int i)
{
	for (;;)
	{
		float i = 33.0;
		printf("%f\n", i);   // 33.0
		goto exit;
	}
exit:
	printf("%d\n", i);   // 怎么是23呢？
}

void f2(void)
{
	printf("%d\n", i);  // 13
}