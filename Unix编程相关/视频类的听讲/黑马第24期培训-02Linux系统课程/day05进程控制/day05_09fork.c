#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Begin ....\n");

	pid_t pid = fork();  // 单独执行，是不是出现2个进程，会出现end打印了2次  【从fork开始了分叉】
	printf("End ...\n");

	return 0;
}