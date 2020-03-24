#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

//要先写再读，同时读关闭的话，写也会自动关闭

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("./a.out fifoname\n");
		return -1;
	}

	printf("begin open read ...\n"); //在写了read()后追加的这行

	int fd = open(argv[1], O_RDONLY);

	printf("begin open read ...\n"); //在写了read()后追加的这行
	
	char buf[256];
	int ret;
	//循环读
	while (true)
	{
		memset(buf, 0x0, sizeof(buf));
		ret = read(fd, buf, sizeof(buf));
		if (ret >0)
		{
			printf("read: %s\n", buf);
		}
	}
	// 关闭描述符
	close(fd);
	return 0;
}