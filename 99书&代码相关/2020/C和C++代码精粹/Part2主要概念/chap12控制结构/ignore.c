// 程序清单12.10  关闭键盘中断请求
// ignore.c:忽略交互式的注意信号键

#include <stdio.h>
#include <signal.h>

int main()
{
	char buf[BUFSIZE];
	int i;
	// 忽略键盘中断
	signal(SIGINT, SIG_IGN);
	while (gets(buf))
		puts(buf);

	// 恢复默认注意键处理 因而使用者能由键盘进行异常中断
	signal(SIGINT, SIG_DFL);
	for (i = 1;;++i)
	{
		printf("%d%c", i, (i % 15 ? '' : '\n'));
	}

}