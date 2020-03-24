#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thr(void *arg)
{
	while (true)
	{
		//**这里啥也没写，就是没有取消点**。
		//注释掉这部分后，就没法杀死
		//printf("I am a thread, very happy! tid=%lu\n", pthread_self());
		//sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);

	sleep(5);//等5秒后再杀
	pthread_cancel(tid);

	void* ret;
	//pthread_join(tid, NULL);
	pthread_join(tid, &ret);
	printf("thread exit with %d\n", (int)ret);//退出是-1
	return 0;
}