#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void catch_sig(int num)
{
	printf("begin call ,catch %d sig\n", num);
	sleep(5);//为了模拟捕获函数执行时间较长
	printf("end call ,catch %d sig\n", num);
}

int main()
{
	struct sigaction act;
	act.sa_flags = 0;
	act.sa_handler = catch_sig;
	sigemptyset(&act.sa_mask);

	//临时屏蔽sa_mask  【相当于 捕捉时 用了2个信号】
	sigaddset(&act.sa_mask, SIGQUIT);//临时屏蔽ctr+\信号  【当函数执行完了，会恢复原状，会执行ctrl+\】

	//注册一下捕捉函数
	sigaction(SIGINT, &act, NULL);
	while (true)
	{
		printf("who can kill me?\n");
		sleep(1);
	}
	return 0;
}

//kill 14 进程id。  【发了一个它能捕获的信号】