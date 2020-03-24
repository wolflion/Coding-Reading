#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>


void *thr(void *arg)
{
	printf("I am a thread\n");
	return NULL;
}

int main()
{
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);  //设置属性分离，就不需要回收，后面就会显示无效，可以注释一下


	pthread_t tid;
	pthread_create(&itd, &attr, thr, NULL);

	int ret;
	if ((ret = pthread_join(tid,NULL))>0)
	{
		printf("join err:%d,%s\n", ret, strerror(ret));
	}
	
	pthread_attr_destory(&attr); //销毁属性

	return 0;
}