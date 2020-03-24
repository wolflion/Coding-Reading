#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> //sleep()的调用
#include <stdlib.h>

int main()
{
	printf("I will die!\n");
	sleep(2);
	//raise(SIGKILL);  //kill(getpid(),sig)
	abort();//自己给自己发送一个SIGABRT信号
	return 0;
}