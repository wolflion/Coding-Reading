#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
	/*
	如果是新创建一个文件
	int fd = open("mem.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
	ftruncate(fd,8);
	*/

	int fd = open("mem.txt",O_RDWR);

	//char *mem = mmap(NULL,8,PORT_READ|PORT_WRITE,MAP_SHARED,fd,0);
	char *mem = mmap(NULL, 8, PORT_READ | PORT_WRITE, MAP_PRIVATE, fd, 0);  //如果这里写20，超过8了，跟文件大小有关
	if (mem == MAP_FAILED)
	{
		perror("mmap err");
		return -1;
	}

	//拷贝数据
	strcpy(mem, "hello");

	//释放
	if (munmap(mem, 8) < 0)//8是length
	{
		perror("munmap err");
	}
	close(fd);
	return 0;
}