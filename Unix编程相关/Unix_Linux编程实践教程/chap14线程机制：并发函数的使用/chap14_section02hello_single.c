//hello_single.c--a single threaded hello world program

#include <stdio.h>
#define NUM 5

void print_msg(char*);

int main()
{
	print_msg("hello");
	print_msg("world\n");
	return 0;
}

void print_msg(char* m)
{
	for (int i = 0; i < NUM;i++)
	{
		printf("%s", m);
		fflush(stdout);
		sleep(1);  //�ü� unistd.h ͷ�ļ�����Ȼgcc��澯��g++�ᱨ��
	}
}