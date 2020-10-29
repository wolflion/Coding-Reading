#define _CRT_SECURE_NO_WARNINGS
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma comment(lib,"pthreadVC2.lib")

void* processfd(void* arg);

// create threads to monitor fds
void monitorfd(int fd[], int numfds)
{
	int error, i;
	pthread_t* tid;
	if ((tid = (pthread_t *)calloc(numfds,sizeof(pthread_t))) == NULL)
	{
		perror("Failed to allocate space for thread IDs");
		return;
	}

	// create a thread for each file descriptor
	for (i = 0; i < numfds; i++)
	{
		if (error = pthread_create(tid + i, NULL, processfd, (fd + i)))
		{
			fprintf(stderr, "Failed to create %d: %s\n", i, strerror(error));
			tid[i] = pthread_self();
		}
	}

	for (i = 0; i < numfds; i++)
	{
		if (pthread_equal(pthread_self(), tid[i]))
			continue;
		if (error = pthread_join(tid[i], NULL))
			fprintf(stderr, "Failed to join thread %d: %s\n", i, strerror(error));
	}
	free(tid);
	return;
}