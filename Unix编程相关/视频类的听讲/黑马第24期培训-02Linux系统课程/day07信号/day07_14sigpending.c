#include <stdio.h>
#include <unistd.h>
#include <singal.h>

int main()
{
	sigset_t pend，sigproc;  //sigproc是阻塞信号
	//设置阻塞信号，等待按键产生信号
	sigemptyset(&sigproc); //先清空
	sigaddset(&sigproc, SIGINT);  //加个CTRL+C的信号
	sigaddset(&sigproc, SIGQUIT);
	//9号信号不给阻塞，设置也不好使，代码试一下
	sigaddset(&sigproc, SIGKILL);
	//设置阻塞信号集
	sigprocmask(SIG_BLOCK, &sigproc, NULL);
	//循环取未决信号集，打印
	while (true)
	{
		sigpending(&pend);
		int i = 1;
		for (i = 1; i < 32; i++)
		{
			if (sigismember(pend, i) == 1)  //在信号集
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
		sleep(1);
	}
	return 0;
}