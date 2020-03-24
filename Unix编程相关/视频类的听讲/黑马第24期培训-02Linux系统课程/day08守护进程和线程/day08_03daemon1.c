#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

#define _FILE_NAME_FORMAT_ "%s/log/mydaemon.%ld"    //�����ļ���ʽ��

void touchfile(int num)
{
	char *HomeDir = getenv("HOME");
	char strFilename[256] = { 0 };
	sprintf(strFilename, _FILE_NAME_FORMAT_, HomeDir,time(NULL));

	int fd = open(strFilename, O_RDWR | O_CREAT, 0666);

	if (fd < 0)
	{
		perror("open err");
		exit(1);
	}
	close(fd);
}

int main()
{
	//�����ӽ��̣��������˳�
	pid_t pid = fork();
	if (pid > 0)
	{
		exit(1);
	}
	//���᳤
	setsid();
	//��������
	umask(0);
	//�л�Ŀ¼
	chdir(getenv("HOME"));//�л���HOMEĿ¼
	//�ر��ļ�������
	//close(0);close(1);close(2);
	//ִ�к����߼�
	struct itimerval myit = { { 60, 0 }, { 60, 0 } };  //���ԵĻ������Ը�Ϊ1��
	setitimer(ITIMER_REAL, &myit, NULL);
	struct sigaction act;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	act.sa_handler = touchfile;
	sigaction(SIGALARM, &act, NULL);
	while (true)
	{
		//ÿ��1min��$HOME/log�´����ļ�
		//sleep(60); //������ɵ�İ취
		sleep(1);
	}
	//�˳�
	return 0;
}
