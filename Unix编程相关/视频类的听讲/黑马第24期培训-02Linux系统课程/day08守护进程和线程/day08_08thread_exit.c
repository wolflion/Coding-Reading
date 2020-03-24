#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thr(void *arg)
{
	printf("I am a thread, pid=%d,tid=%lu\n", getpid(), pthread_self());
	//return NULL;
	pthread_exit(NULL);
	//exit(1);  // ������Ļ��������̶��˳��ˣ������I will out���Ͳ����ӡ��
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);
	printf("I am main thread, pid=%d,tid=%lu\n", getpid(), pthread_self());

	sleep(10);
	printf("I will out\n");
	pthread_exit(NULL);
	return 0;
}