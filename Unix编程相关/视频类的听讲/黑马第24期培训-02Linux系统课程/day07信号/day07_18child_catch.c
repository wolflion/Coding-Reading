#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void catch_sig(int num)
{
	//�ӽ���˯�����
#if 0
	pid_t wpid = waipid(-1,NULL,WNOHANG);
	if (wpid > 0)
	{
		printf("wait child %d ok\n", wpid);
	}
#endif
	//�ӽ���û��˯sleep(i)�����
	pid_t wpid;
	while ((wpid = waitpid(-1,NULL,WNOHANG)) > 0)
	{
		printf("wait child %d ok\n", wpid);
	}
}

int main()
{
	int i = 0;
	pid_t pid;
	//�ڴ����ӽ���֮ǰ������SIGCHLD�ź�
	sigset_t myset,oldset;
	sigemptyset(&myset);
	sigaddset(myset, SIGCHLD);
	//oldset���ڱ����ֳ���������SIGCHLD�������źż�
	sigprocmask(SIG_BLOCK, &myset,&oldset);

	for (i = 0; i < 10; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			break;
		}
	}

	if (i==10)
	{
		sleep(2); //��˯2�룬���ӽ������ˣ�����1���������ա�
		//parent
		struct sigaction act;
		act.sa_flags = 0;
		sigemptyset(&act.sa_mask);
		act.sa_handler = catch_sig;
		//����������SIGCHLD����sigactionǰҪ�ָ�
		
		sigaction(SIGCHLD, &act, NULL);  //��catchǰ���ӽ��̶����ˡ�

		//�������
		sigprocmask(SIG_SETMASK��&oldset,NULL);

		while (true)
		{
			sleep(1);
		}
	}
	else if (i < 10)
	{
		//son
		printf("I am %d child, pid=%d\n", i, getpid());
		//û��sleep()�����ܻ�û����ȫ��Ҳ�п�����ȫ��
		//sleep(i);  //�����˯������������ֻ��9�����̣��ټ�һ����ʬ���̡� **�ź�һ��ֻ�ܻ���һ��**������˯������������޸Ĳ�׽����
	}
}