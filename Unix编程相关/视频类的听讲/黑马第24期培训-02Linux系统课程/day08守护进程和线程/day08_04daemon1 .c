#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{
	char strFileName[256] = { 0 };

	while (true)
	{
		memset(strFileName, 0x00, sizeof(strFileName));
		sprintf(strFileName, "%s/log/zhen2.%ld", getenv("HOME"), time(NULL));
		int fd = open(strFileName, O_RDONLY | O_CREAT, 0664);
		if (fd < 0)
		{
			perror("open err");
			exit(1);
		}
		close(fd);
		sleep(5);//每隔5秒创建一下
	}
	return 0;
}