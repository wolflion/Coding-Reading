//借助原先的代码，可以作为一个模板，单独写出来一下
#include<sys/epoll.h>   //【K跳转】

//创建epoll树根节点
int epfd = epoll_create(2000);
//初始化epoll树
struct epoll_event ev;
ev.events = EPOLLN;
ev.data.fd = lfd;
epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);

//存储发生变化的fd对应信息
struct epoll_event all[2000];

while (true)
{
	//使用epoll通知内核fd文件IO检测
	//参数-1表示阻塞状态
	int ret = epoll_wait(epfd,all,sizeof(all)/sizeof(all[0]),-1);

	//遍历all数组中的前ret个元素
	for (int i = 0; i < ret; ++i)
	{
		int fd = all[i].data.fd;
		//判断是否有新连接
		if (fd == lfd)
		{
			//接收连接请求--accept不阻塞
			int cfd = accept(lfd,(struct sockaddr*)&client_addr,&cli_len);
			if (cfd == -1)
			{
				perror("accept error");
				exit(1);
			}
			//将新得到的cfd挂在树上
			struct epoll_event temp;
			temp.events = EPOLLIN;
			temp.data.fd = cfd;
			epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &temp);
		}
		//已经连接的客户端有数据发送过来
		else
		{
			//处理已经连接的客户端发来的数据
			if (!all[i].events &EPOLLIN) //in,out类型  【只处理读事件】
			{
				//结果是0，跳过当次循环，比如人家是EPOLLOUT
				continue;
			}
			//读数据
			char buf[1024] = { 0 };
			int len = recv(fd,buf,sizeof(buf),0);
			if (len == 0)
			{
				printf("client disconnected ...\n");
				//客户端关闭了连接
				close(fd);
				//检测的fd从树上删除
				epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
			}
			else if (len == -1)
			{
				perror("recv error");
				exit(1);
			}
			else
			{
				//写数据
				printf("recv buf: %s\n", buf);
				//send();
				write(fd,buf,len);
			}
		}
	}
}