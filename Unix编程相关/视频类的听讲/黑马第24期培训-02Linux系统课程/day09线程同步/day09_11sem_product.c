#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

//生产者判断一下，饼筐里有没有空间  **生产者也有自己的判断变量**
//消费者判断一下，饼筐里有没有饼，**消费者得有自己的判断变量**
sem_t blank, xfull;

#define _SEM_CNT_ 5

void *thr_producter(void *arg)
{
	return NULL;
}

void *thr_customer(void *arg)
{
	return NULL;
}

int main()
{
	sem_init(&blank, 0, _SEM_CNT_);
	sem_init(&xfull, 0, 0);//消费者一开始的初始化默认没有产品

	//创建线程
	pthread_t tid[2];
	pthread_create(&tid[0], NULL, thr_producter, NULL);
	pthread_create(&tid[1], NULL, thr_customer, NULL);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	sem_destroy(&blank);
	sem_destroy(&xfull);
	return 0;
}