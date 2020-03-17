//hello_multi.c--a multi-threaded hello world program

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define NUM 5

void* print_msg(void*);

int main()
{
	pthread_t t1, t2;
	pthread_creat(&t1, NULL, print_msg, (void*)"hello");//我看视频里最后一个参数是NULL
	pthread_creat(&t2, NULL, print_msg, (void*)"world\n");
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}

void* print_msg(void* m)
{
	char *cp = (char*)m;
	for (int i = 0; i < NUM;i++)
	{
		printf("%s", m);
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}