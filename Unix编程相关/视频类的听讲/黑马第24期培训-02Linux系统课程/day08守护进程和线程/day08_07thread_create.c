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
	sleep(1);  //如果不睡1秒，会调用return，主控线程调用return，相当于整个进程退出了，所以线程也没了。
	//不睡1秒的话，可以用pthread_exit()退出
	return 0;
}