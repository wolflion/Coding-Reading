#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thr(void *arg)
{
	while (true)
	{
		//**����ɶҲûд������û��ȡ����**��
		//ע�͵��ⲿ�ֺ󣬾�û��ɱ��
		//printf("I am a thread, very happy! tid=%lu\n", pthread_self());
		//sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);

	sleep(5);//��5�����ɱ
	pthread_cancel(tid);

	void* ret;
	//pthread_join(tid, NULL);
	pthread_join(tid, &ret);
	printf("thread exit with %d\n", (int)ret);//�˳���-1
	return 0;
}