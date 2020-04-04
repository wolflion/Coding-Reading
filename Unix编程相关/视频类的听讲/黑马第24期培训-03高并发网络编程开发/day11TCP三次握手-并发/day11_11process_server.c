#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

//进程回收函数
void recyle(int num)
{
	pid_t pid;
	while ((pid = waitpid(-1,NULL,WNOHANG)) >0 ）
	{
		//回调成功
		printf("child died, pid = %d\n",pid);
	}
}


int main(int argc, const char* argv[])
{
	if (argc < 2)
	{
		printf("eg: ./a.out port\n");
		exit(1);
	}
	struct sockaddr_in serv_addr;
	socklen_t serv_len = sizeof(serv_addr);
	int port = atoi(argv[i]);

	//创建套接字
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	//初始化服务器 sockaddr_in
	memset(&serv_addr, 0, serv_len);
	serv_addr.sin_family = AF_INET; //地址族
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //监听本机所有的IP
	serv_addr.sin_port = htons(port);//设置端口

	//绑定IP和端口
	bind(lfd, (struct sockaddr*)&serv_addr, serv_len);

	//设置同时监听的最大个数
	listen(lfd, 36);
	printf("Start accept ......\n");


	//新增： 使用信号回收子进程pcb
	struct sigaction act;
	act.handler = recyle;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGCHLD, &act, NULL);

	struct sockaddr_in client_addr;
	socklen_t cli_len = sizeof(client_addr);
	while (true)
	{
		//父进程 接收连接请求
		//注意：accept阻塞的时候被信号中断，处理完信号操作之后，回来之后不阻塞了，直接返回-1，这时候
		//errno=EINTR
		int cfd = accept(lfd, (struct sockaddr*)&client_addr, &cli_len);
		while (cfd == -1 && && errno = EINTR)//解决方案：
		{
			cfd = accept(lfd, (struct sockaddr*)&client_addr, &cli_len);
		}
#if 0
		if (cfd == -1)  
		{
			perror("accept error");
			exit(1);
		}
#endif

		printf("connect successful\n");

		//创建子进程
		pid_t pid = fork();
		if (pid == 0)
		{
			close(lfd);
			//child process
			//通信
			char ip[64];
			while (true)
			{
				//client ip和port
				printf("client IP:%s, port: %s\n",
					inet_ntop(AF_INET, &client_addr.sin_addr.s_addr), ip, sizeof(ip)),
					ntohs(client_addr.sin_port));
				char buf[1024];
				int len = read(cfd, buf,sizeof(buf));
				if (len == -1)
				{
					perror("read error");
					exit(1);
				}
				else if (len == 0)
				{
					printf("客户端断开了连接\n");
					close(cfd);
					break;
				}
				else
				{
					//正常情况
					printf("recv buf:%s\n", buf);
					write(cfd, buf, len);
				}
			}
			//子进程任务完成，退出
			return 0;
		}
		else if (pid > 0)
		{
			//parent process
			close(cfd); 
		}
	}
	close(lfd);
	return 0;
}

//nc 127.1 9876；0 可以简写，9876是端口号， nc是啥命令？