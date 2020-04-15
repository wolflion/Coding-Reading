//先记住核心，具体用啥了，再补充定义

int main()
{
	//创建监听的套接字
	int lfd = socket();
	//绑定
	bind();
	//监听
	listen();

	//epoll树根节点
	int epfd = epoll_create(3000);

	//存储发生变化的fd对应信息
	struct epoll_event all[3000];

	//初始化
	//监听的lfd挂在epoll树上
	struct epoll_event ev;

	//在ev中init fd的信息
	ev.events = EPOLLN;
	ev.data.fd = lfd;

	epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);

	//委托内核一直去检测事件
	while (true)
	{
		//这里面要有efd，所以得在外面epoll_create()
		int ret = epoll_wait(efd,all,3000,-1);  //ret就是返回多少个  【**这是个核心**】

		//根据ret遍历all数组
		for (int i = 0; i < ret;++i)
		{
			//两类文件描述符（有新的连接，已经连接的客户端有数据发送过来）
			int fd = all[i].data.fd;
			//有新的连接
			if (fd == lfd)
			{
				//接收连接请求--accept不阻塞
				int cfd = accept();
				//cfd挂在树上
				ev.events = EPOLLIN;
				ev.data.fd = cfd;
				epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
			}
			//已经连接的客户端有数据发送过来
			else
			{
				//只处理客户端发来的数据
				if (all[i].events &EPOLLIN) //in,out类型
				{
					//结果是0，跳过当次循环，比如人家是EPOLLOUT
					continue;
				}
				//读数据
				int len = recv();
				if (len == 0)
				{
					//客户端关闭了连接
					close(fd);
					//检测的fd从树上删除
					epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
				}
				//写数据
				send();
			}
		}
	}
}