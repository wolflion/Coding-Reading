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
	//用pthread_exit((void*)100)效果是一样的
	//pthread_exit((void*)100);
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);

	void *ret;
	pthread_join(tid,&ret);//线程回收，也是阻塞等待回收  【*thr()里加了个sleep】

	printf("ret exit with %d\n", (int)ret);

	pthread_exit(NULL);
}