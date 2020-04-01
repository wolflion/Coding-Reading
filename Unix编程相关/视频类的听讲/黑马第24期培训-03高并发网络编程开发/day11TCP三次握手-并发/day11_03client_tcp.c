//在SecureCRT中用了xmyheader<snip>的方式，直接输入了内容

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>  //这是必须的头文件

int main(int argc, const char* argv[])
{
	if (argc<2)
	{
		printf("eg: ./a.out port\n");
		exit(1);
	}

	int port = atoi(argv[1]);  //argv[0]就是a.out

	//创建套接字
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	//连接服务器
	struct sockaddr_in serv;
	memset(&serv, 0, sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_port = htons(port);
	//第二个参数是 点分十进制的IP
	inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
	//这样可以无须用htonl()才转个整型了
	//serv.sin_addr.s_addr=htonl();
	
	connect(fd, (struct sockaddr*)&serv, sizeof(serv));

	//通信
	while (true)
	{
		//发送数据
		char buf[1024];
		printf("请输入要发送的字符串\n");
		fgets(buf,sizeof(buf),stdin);//从终端接收数据
		write(fd, buf, strlen(buf));

		//等待接收数据
		int len = read(fd, buf, sizeof(buf));

		if (len==-1)
		{
			perror("read error");
			exit(1);
		}
		else if (len == 0)
		{
			printf("服务器端关闭了连接\n");  //服务器端关闭了，这里read()就不再阻塞
			break;
		}
		else
		{
			printf("recv buf %s\n", buf);
		}
	}
	close(fd);

	return 0;
}