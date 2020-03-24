#include <stdio.h>
#include <unistd.h>

int main()
{
	int ret = 0;
	ret = alarm(6);   //第一次返回0
	printf("ret = %d\n", ret);
	sleep(2);           
	ret = alarm(5);  //因为睡了2秒，这个返回值是4，有可能不准
	printf("ret = %d\n", ret);
	while (true)
	{
		printf("lai da wo ba!\n");
		sleep(1);
	}
	return 0;
}