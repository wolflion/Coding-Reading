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
#include <pthread.h>

//自定义数据结构，存储线程的数据
typedef struct SockInfo
{
	int fd;
	struct sockaddr_in addr;
	pthread_t id;
}SockInfo;

//子线程处理函数
void* worker(void *arg)
{
	char ip[64];
	char buf[1024];
	SockInfo* info = (SockInfo*)arg;
	//通信
	while (true)
	{
		printf("Client IP: %s, port: %d\n",
			inet_ntop(AF_INET, &info->addr.sin_addr.s_addr, ip, sizeof(ip)),
			ntohs(info->addr.sin_port));

		int len = read(info->fd, buf, sizeof(buf));
		if (len == -1)
		{
			perror("read error");
			pthread_exit(NULL);//只退出当前
			//exit(1);就退出所有
		}
		else if (len == 0)
		{
			printf("客户端已经断开了连接\n");
			close(info->fd);
			break;
		}
		else
		{
			printf("recv buf: %s\n", buf);
			write(info->fd, buf, len);
		}
	}
	return NULL;
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

	//新增
	SockInfo info[256];
	int i=0;
	//新增 结束

	//规定fd == -1，是无效描述符
	for (size_t i = 0;i<sizeof(info)/sizeof(info[0]);++i)
	{
		info[i].fd = -1;
	}
	socklen_t cli_len = sizeof(struct sockaddr_in);
	while (true)
	{
		//选一个没有被使用的，而且是最小的数组元素
		for (size_t i = 0; i < 256;++i)
		{
			if (info[i].fd == -1)
			{
				break;  
			}
		}

		if (i == 256)
		{
			break;
		}

		//主线程--等待接受连接请求
		info[i].fd = accept(lfd, (struct sockaddr*)&info[i].addr, &cli_len);
	
		//创建子线程--通信
		pthread_create(&info[i].id, NULL, worker, &info[i]);
		//回收子线程--设置线程分离
		pthread_detach(info[i].id);

		//前面判断过了，这里注释掉 
#if 0
		i++;
		if (i == 256)
		{
			break;
		}
#endif
	}
	close(lfd);

	//只退出主线程
	pthread_exit(NULL);
	return 0;
}

//nc 127.1 9876；0 可以简写，9876是端口号， nc是啥命令？