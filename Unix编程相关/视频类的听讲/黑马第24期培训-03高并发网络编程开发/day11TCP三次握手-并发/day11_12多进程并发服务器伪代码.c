int fds[];

typedef struct sockInfo
{
	pthread_t id;
	int fd;
	struct sockaddr_in addr; 
}sockInfo;


void* worker(void* arg)
{
	while ()
	{
		//打印客户端ip和port
		read();
		write();
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

	//int cfd; //用一个数组，跟保存每个子线程对应的文件描述符
	sockInfo sock[256];
	//父线程  【主线程的处理动作】
	while (1)
	{
		sock[i].fd = accept(lfd,&client,&len);
		//创建子线程
		pthread_create(&sock[i].id,NULL,worker,&sock[i]);  //第1个连接
		pthread_deatch(sock[i].id);
	}
}