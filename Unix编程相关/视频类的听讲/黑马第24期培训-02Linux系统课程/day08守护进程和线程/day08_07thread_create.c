#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thr(void *arg)
{
	printf("I am a thread! pid=%d, tid = %lu\n", getpid(),pthread_self());
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);
	printf("I am a main thread, pid=%d,tid=%lu\n", getpid(), pthread_self());
	sleep(1);  //�����˯1�룬�����return�������̵߳���return���൱�����������˳��ˣ������߳�Ҳû�ˡ�
	//��˯1��Ļ���������pthread_exit()�˳�
	return 0;
}