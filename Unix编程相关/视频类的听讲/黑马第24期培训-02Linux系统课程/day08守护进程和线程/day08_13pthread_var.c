#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int var = 100;

void *thr(void *arg)
{
	printf("I am a thread, self = %lu, var = %d\n", pthread_self(),var);//1003
	sleep(2);
	var = 1001;
	printf("I am a thread, self = %lu, var = %d\n", pthread_self(),var);
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);

	pthread_detach(tid); //线程分离
	printf("I am main thread, self = %lu, var = %d\n", pthread_self(), var);  // var应该是100
	var = 1003;
	sleep(5);
	printf("I am main thread, self = %lu, var = %d\n", pthread_self(), var);//1001
	int ret = 0;
	if ((ret = pthread_join(tid, NULL)) > 0）  //两个互斥，用了pthread_detach()后，就不用pthread_join()回收
	{
		printf("join err: %d,%s\n", ret, strerror(ret));
	}
	return 0;
}