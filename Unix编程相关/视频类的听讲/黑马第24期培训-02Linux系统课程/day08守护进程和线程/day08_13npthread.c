//创建多个线程
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thr(void *arg)
{
	//malloc()的话，可以在main()里释放
	//int num = (int)arg;
	int num = *(int*)arg;
	printf("I am %d thread, self = %lu\n", num, pthread_self());
	//return NULL;
	return (void*)(100 + num);
}

int main()
{
	pthread_t tid[5];
	int i;
	for (i = 0; i < 5;i++)
	{
		//pthread_create(&tid[i], NULL, thr, (void*)i); //传值是稳定的
		pthread_create(&tid[i], NULL, thr, (void*)&i);//极不稳定的原因，取地址极不稳定。多执行几次会看到差异。【用啥方法扩展一下】
	}
	for (i = 0; i < 5;i++)
	{
		void *ret;
		pthread_join(&tid[i], &ret);//有序的原因，阻塞等待。
		printf("i=%d,ret=%d\n", i, (int)ret);
	}
	return 0;
}