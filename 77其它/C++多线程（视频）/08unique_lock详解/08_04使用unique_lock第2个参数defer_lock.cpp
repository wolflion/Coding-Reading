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
		#if 0
		my_mutex.lock(); //要先lock后，才能使用unique_lock中的adopt_lock参数。
		std::unique_lock<std::mutex> sbguard1(my_mutex,std::adopt_lock);
		#endif
		//用try_to_lock的前提下，千万不能先调用lock()
		std::unique_lock<std::mutex> sbguard1(my_mutex,std::try_to_lock);
		if(sbguard1)
		{
			//拿到锁了才操作
			msgRecvQueue.push_back(i); //假设数字i就是收到的命令，直接弄到消息队列里来
			//其它操作
		}
		else
		{
			//没有拿到锁
			cout<<"没有拿到锁"<<endl;
		}
		
		
	}
	}
	
	bool outMsgLULProc(int &command)
	{
		std::unique_lock<std::mutex> sbguard1(my_mutex);
		
		//写了个看出unique_lock优化的例子  【这个地方休息20秒，另一个线程也被lock了20秒，没拿到锁，卡住了】
		std::chrono::millseconds dura(20000); //1秒 = 1000毫秒，所以就20秒
		std::this_thread::sleep_for(dura);  //休息20秒
		
		if(!msgRecvQueue.empty())
		{
			//消息队列不为空
			command = msgRecvQueue.front(); //从头取，从尾巴插。【返回第一个元素，但不检查元素是否存在】
			msgRecvQueue.pop_front(); //移除第一个元素，但不返回。
			return true;
		}
		return false;
	}
	
	//线程2：把数据从消息队列里取出的过程。  【消息队列就是容器】
	void outMsgRecvQueue()
	{
		int command = 0;
		for(int i=0;i<100000;++i)
	{
		
		bool result = outMsgLULProc(command);
	
		if(result == true)
		{
			cout<<"取出一个元素，成功"<<endl;
			//继续处理
			//....
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
	std::mutex my_mutex;  //创建一个互斥量
}


int main()
{
	A myobj;
	std::thread myOutMsgObj(&A::outMsgRecvQueue,&myobj);//第2个参数是引用，才能保证线程里用的是同一个对象
	std::thread myInMsgObj(&A::inMsgRecvQueue,&myobj);
	
	
	myOutMsgObj.join();
	myInMsgObj.join();
	
	//保护共享数据，操作时，用代码把共享数据锁住，操作数据，解锁
	//其它想操作共享数据的线程必须得等待解锁，锁住，操作，解锁
	
	return 0;
}