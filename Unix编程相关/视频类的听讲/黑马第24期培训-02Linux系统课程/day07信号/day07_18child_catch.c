#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void catch_sig(int num)
{
	//子进程睡的情况
#if 0
	pid_t wpid = waipid(-1,NULL,WNOHANG);
	if (wpid > 0)
	{
		printf("wait child %d ok\n", wpid);
	}
#endif
	//子进程没有睡sleep(i)的情况
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
	//在创建子进程之前，屏蔽SIGCHLD信号
	sigset_t myset,oldset;
	sigemptyset(&myset);
	sigaddset(myset, SIGCHLD);
	//oldset用于保留现场，设置了SIGCHLD到阻塞信号集
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
		sleep(2); //先睡2秒，等子进程退了，这样1个都不回收。
		//parent
		struct sigaction act;
		act.sa_flags = 0;
		sigemptyset(&act.sa_mask);
		act.sa_handler = catch_sig;
		//可以先屏蔽SIGCHLD，在sigaction前要恢复
		
		sigaction(SIGCHLD, &act, NULL);  //在catch前，子进程都死了。

		//解除屏蔽
		sigprocmask(SIG_SETMASK，&oldset,NULL);

		while (true)
		{
			sleep(1);
		}
	}
	else if (i < 10)
	{
		//son
		printf("I am %d child, pid=%d\n", i, getpid());
		//没有sleep()，可能会没有收全，也有可能收全。
		//sleep(i);  //如果不睡觉会怎样？【只有9个进程，再加一个僵尸进程】 **信号一次只能回收一个**，这是睡的情况。否则修改捕捉函数
	}
}