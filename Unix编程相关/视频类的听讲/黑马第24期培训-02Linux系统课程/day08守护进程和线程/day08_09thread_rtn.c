#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thr(void *arg)
{
	printf("I am a thread. tid=%lu\n", pthread_self());
	//return NULL;
	sleep(5);
	printf("I am a thread. tid=%lu\n", pthread_self());
	return (void*)100;
	//��pthread_exit((void*)100)Ч����һ����
	//pthread_exit((void*)100);
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);

	void *ret;
	pthread_join(tid,&ret);//�̻߳��գ�Ҳ�������ȴ�����  ��*thr()����˸�sleep��

	printf("ret exit with %d\n", (int)ret);

	pthread_exit(NULL);
}