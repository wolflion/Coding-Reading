#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("./a.out fifoname\n");
		return -1;
	}

	//当前目录有一个myfifo文件

	printf("begin open write...\n"); //在写了read()后追加的这行

	// 打开fifo文件
	int fd = open(argv[1], O_WRONLY);

	printf("end open write...\n"); //在写了read()后追加的这行
	// 写
	char buf[256];
	int num = 1;
	while (true)
	{
		memset(buf, 0x00, sizeof(buf));
		sprintf(buf,"xiaoming%04d",num++);
		write(fd, buf, strlen(buf));
		sleep(1);
	}
	// 关闭描述符
	close(fd);
	return 0;
}