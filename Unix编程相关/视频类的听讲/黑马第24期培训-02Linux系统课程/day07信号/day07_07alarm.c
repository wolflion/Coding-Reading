#include <stdio.h>
#include <unistd.h>

int main()
{
	int ret = 0;
	ret = alarm(6);   //��һ�η���0
	printf("ret = %d\n", ret);
	sleep(2);           
	ret = alarm(5);  //��Ϊ˯��2�룬�������ֵ��4���п��ܲ�׼
	printf("ret = %d\n", ret);
	while (true)
	{
		printf("lai da wo ba!\n");
		sleep(1);
	}
	return 0;
}