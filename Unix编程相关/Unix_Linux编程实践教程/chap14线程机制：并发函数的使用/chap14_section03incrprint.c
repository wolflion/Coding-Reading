//incprint.c --one thread increment, the other prints
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define  NUM  5

int counter = 0;

void* print_count(void *);

int main()
{
	pthread_t t1;
	pthread_create(&t1, NULL, print_count, NULL);

	for (int i = 0; i < NUM;i++)
	{
		counter++;
		sleep(1);
	}
	pthread_join(t1, NULL);//等待线程终止
}

void* print_count(void *m)
{
	for (int i = 0; i < NUM;i++)
	{
		printf("count = %d\n", counter);
		sleep(1);
	}
	return NULL;
}