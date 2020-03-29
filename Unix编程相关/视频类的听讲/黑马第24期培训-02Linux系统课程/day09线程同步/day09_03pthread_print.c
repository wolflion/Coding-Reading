#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;

void *thr1(void *arg)
{
	while (true)
	{
		//先上锁
		pthread_mutex_lock(&mutex); //加锁当有线程已经加锁的时候会阻塞
		//这里面的区域是 临界区
		printf("hello");  //没有换行，没有行缓冲，输不出来
		sleep(rand() % 3); //模拟失去cpu
		printf("world");
		//sleep(rand() % 3);  //这个地方也是一样的原因
		//释放锁
		pthread_mutex_unlock(&mutex);
		sleep(rand() % 3);
	}
}

void *thr2(void *arg)
{
	while (true)
	{
		//先上锁
		pthread_mutex_lock(&mutex);
		printf("HELLO");
		sleep(rand()%3);
		printf("WORLD");
		//sleep(rand() % 3);  //这个换位置，就一直被thr2()抢占
		//释放锁
		pthread_mutex_unlock(&mutex);
		sleep(rand() % 3);
	}
}

int main()
{
	pthread_t tid[2];
	pthread_create(&tid[0], NULL, thr1, NULL);
	pthread_create(&tid[1], NULL, thr2, NULL);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	return 0;
}