#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Begin ....\n");

	pid_t pid = fork();  // ����ִ�У��ǲ��ǳ���2�����̣������end��ӡ��2��  ����fork��ʼ�˷ֲ桿
	printf("End ...\n");

	return 0;
}