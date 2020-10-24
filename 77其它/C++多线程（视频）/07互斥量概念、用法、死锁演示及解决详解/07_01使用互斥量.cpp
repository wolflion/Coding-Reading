//准备用成员函数作为线程函数的方法来写线程；

class A
{
	public:
	//线程1：把收到的消息（玩家命令）入到一个队列的线程
	void inMsgRecvQueue()
	{
	for(int i=0;i<100000;++i)
	{
		cout<<"执行插入1个元素"<<i<<endl;
		msgRecvQueue.push_back(i); //假设数字i就是收到的命令，直接弄到消息队列里来
	}
	}
	
	//线程2：把数据从消息队列里取出的过程。  【消息队列就是容器】
	void outMsgRecvQueue()
	{
		for(int i=0;i<100000;++i)
	{
		if(!msgRecvQueue.empty())
		{
			//消息队列不为空
			int command = msgRecvQueue.front(); //从头取，从尾巴插。【返回第一个元素，但不检查元素是否存在】
			msgRecvQueue.pop_front(); //移除第一个元素，但不返回。
			//这里考虑处理数据
		}
		else
		{
			//消息队列为空
			cout<<"is empty"<<i<<endl;
		}
	}
	}
	cout<<"out end"<<endl;
	}
	private:
	std::list<int>msgRecvQueue; //容器，专门用于代表玩家给咱发送过来的命令
}


int main()
{
	A myobj;
	std::thread myOutMsgObj(&A::outMsgRecvQueue,&myobj);//第2个参数是引用，才能保证线程里用的是同一个对象
	std::thread myInMsgObj(&A::inMsgRecvQueue,&myobj);
	
	
	myOutMsgObj.join();
	myInMsgObj.join();
}