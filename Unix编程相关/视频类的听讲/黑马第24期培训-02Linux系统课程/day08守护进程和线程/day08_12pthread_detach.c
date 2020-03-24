#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *thr(void *arg)
{
	printf("I am a thread, self = %lu\n", pthread_self());
	sleep(4);
	printf("I am a thread, self = %lu\n", pthread_self());
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);

	pthread_detach(tid); //线程分离

	sleep(5);

	int ret = 0;
	if ((ret = pthread_join(tid, NULL)) > 0）  //两个互斥，用了pthread_detach()后，就不用pthread_join()回收
	{
		printf("join err: %d,%s\n", ret, strerror(ret));
	}
	return 0;
}