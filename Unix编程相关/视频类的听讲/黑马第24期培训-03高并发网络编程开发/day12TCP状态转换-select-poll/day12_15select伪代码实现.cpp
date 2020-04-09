int main()
{
	int lfd = socket();
	bind();
	listen();

	//创建 文件描述表

	fd_set reads, temp;
	//初始化
	FD_ZERO(reads);
	//添加 “监听文件描述符”到集合
	fd_set(lfd, &reads);
	int maxfd = lfd;

	//得循环委托
	while (true)
	{
		//委托内核检测
		temp = reads;
		int ret = select(maxfd + 1, &temp, NULL, NULL, NULL);

		//是不是监听的
		if (FD_ISSET(lfd,&temp))  //如果为1，就是有新连接
		{
			//接受新连接
			int cfd = accept();
			//cfd加入读集合
			fd_set(cfd, &reads);
			//更新maxfd
			maxfd = maxfd < cfd ? cfd : maxfd;   //**select是异步的**
		}
		//客户端发送数据
		for (int i = lfd + 1; i <= maxfd; ++i)
		{
			if (FD_ISSET(i,&temp)  //在修改过的里面判断才行
			{
				int len = read();
				if (len == 0)
				{
					//对方断开连接，cfd从读集合中del
					FD_CLR(i, &reads);
				}
				write();
			}
		}
	}
}