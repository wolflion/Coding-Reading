#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	//先创建映射区
	int fd = open("mem.txt", O_RDWR);//这个文件，只是个鸡肋，啥作用也没有，有了个匿名映射
	int *mem = mmap(NULL, 4, PORT_READ | PORT_WRITE, MAP_SHARED, fd, 0);
	if (mem == MAP_FAILED)
	{
		perror("mmap err");
		return -1;
	}
	//fork子进程
	pid_t pid = fork();

	//父进程和子进程交替修改数据
	if (pid == 0)
	{
		//son
		*mem = 100;
		printf("child, *mem=%d\n", *mem);
		sleep(3);
		printf("child, *mem=%d\n", *mem);
	}
	else if (pid > 0)
	{
		//parent
		sleep(1);
		printf("parent, *mem=%d\n", *mem);
		*mem = 1001;
		printf("parent, *mem=%d\n", *mem);
		wait(NULL);
	}

	//释放
	if (munmap(mem, 4) < 0)
	{
		perror("munmap err");
	}
	close(fd);
	return 0;
}