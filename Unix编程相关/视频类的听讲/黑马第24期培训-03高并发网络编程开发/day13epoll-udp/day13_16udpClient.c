﻿#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, const char* argv[])
{
	//创建套接字
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd == -1)
	{
		perror("socket error");
		exit(1);
	}

	//初始化服务器的IP和端口
	struct sockaddr_in serv;
	memset(&serv, 0, sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_port = htons(8765);
	inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);

	socklen_t cli_len = sizeof(client);
	//通信
	char buf[1024] = { 0 };
	while (true)
	{
		char buf[1024] = { 0 };
		fgets(buf, sizeof(buf),stdin);
		//数据的发送--server-ip Port
		sendto(fd, buf, strlen(buf) + 1, 0, (struct sockaddr*)&serv, sizeof(serv));

		//等待服务器发送数据过来，只能用recvfrom()
		recvfrom(fd, buf, sizeof(buf), 0, NULL,NULL);
		
		printf("recv buf: %s\n", buf);
		
	}

	close(fd);

	return 0;
}