#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0;

void *thr1(void *arg)
{
	while (true)
	{
		printf("hello");  //没有换行，没有行缓冲，输不出来
		sleep(rand() % 3); //模拟失去cpu
		printf("world");
		sleep(rand() % 3);
	}
}

void *thr2(void *arg)
{
	while (true)
	{
		printf("HELLO");
		sleep(rand()%3);
		printf("WORLD");
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