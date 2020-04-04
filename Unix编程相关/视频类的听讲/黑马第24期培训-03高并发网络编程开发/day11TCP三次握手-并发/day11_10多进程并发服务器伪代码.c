
int recyle(int num)
{
	while (waipid(-1, NULL, WNOHANG) > 0);
	{

	}
}

int main()
{
	//监听
	int fd = sock();

	//绑定
	bind();

	//设置监听
	listen();


	//新增：信号回收子进程   【在fork之前，会被子进程继承，但没有关系】
	struct sigaction act;
	act.handler = recyle;
	act.sa_flags = 0;
	//act.sa_mask;//设置要屏蔽的信号，没有的话，就置为0
	sigemptyset(&act.sa_mask);
	sigaction(SIGCHLD, &act, NULL);

	//父进程
	while (1)
	{
		int cfd = accept();
		//创建子进程
		pid_t pid = fork();
		//子进程
		if (pid == 0)
		{
			close(fd);
			//通信
			while (true)
			{
				int len = read();
				if (len == -1)
				{
					exit(1);
				}
				else if (len == 0) //对方关闭连接
				{
					close(cfd);//关闭通信描述符
					break;
				}
				else
				{
					write();
				}
			}
			//退出子进程
			retun 0; //exit(1)
		}
		else
		{
			//父进程
			close(cfd);
			//while (waitpid(-1,NULL,WNOHANG) !=-1)  //这么写没有意义，一直在等待回收，应该用信号回收
			{

			}
		}
	}
}