//上节课讲的，双重锁定、双重检查
//每次加锁的效率太低，【先判断是否为空，加锁后，再判断是否为空---双重锁定】

//**condition_variable是个类**，等待一个条件达成，需要跟互斥量配合工作，要生成一个类对象。
class TA
{
private:
	std::mutex my_mutex;  //创建一个互斥量（一个锁头）
    std::condition_variable my_cond;  //生成一个条件对象
};





bool outMsgLULProc(int &command)
{
	
	#if 0
	//双重锁定、双重检查
	if(!msgRecvQueue.empty())
	{
		std::unique_lock<std::mutex> sbguard1(my_mutex);
		
		if(!msgRecvQueue.empty())
		{
			//消息不为空
			command = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			return true;
		}
	}
	return false;
	#endif
}


//把数据从消息队列中取出的线程
void outMsgRecvQueue()
{
	int command = 0;
	while(true)
	{
		std::unique_lock<std::mutex> sbguard1(my_mutex);
		//wait是用来等一个东西
		// lambda的表达式是第2个参数，返回值是false，那么wait将**解锁互斥量**，并堵塞到本行。
		// 那堵塞到什么时候为止呢？堵塞到其它某个线程调用notify_one()成员函数为止。
		
		// 如果lambda的表达返回true,那么wait()直接返回。
		
		// 如果wait没有第2个参数，那么就跟第2个参数返回false效果一样。
		
		// 重要！：wait堵塞的时候，会先解锁互斥量。
		
		// 当其它线程用nodify_one()将本wait(原来是睡着/堵塞)的状态，唤醒。
		// a.唤醒后，要不断重新去锁互斥量。如果获取不到，那么流程就卡在wait这里等着获取。如果获取到了，就继续执行。
		// b.
		// b1、如果wait()有第2个参数，就判断lambda表达式的值；如果false，就解锁互斥量，堵塞
		// b2、如果wait()的第2个参数，返回值是true，流程走下来，**互斥锁是加锁的**。
		// b3、如果wait()没有第2个参数，则wait()返回，流程走下来。
		
		my_cond.wait(sbguard1,[this]{ // 一个lambda表达式就是一个可调用对象（函数）
			if(!msgRecvQueue.empty())
				return true;
			else
				return false;
		}); //条件变量对象，需要跟互斥量配合使用；
		
		// 走到这个地方，互斥锁是锁的；同时msgRecvQueue至少是有一条数据的
		command = msgRecvQueue.front(); //返回第1个元素，但不检查元素是否存在
		msgRecvQueue.pop_front(); //移除第一个元素，但不返回
		//这个地方可以提前unlock掉。
		sbguard1.unlock();  //因为unique_lock的灵活性，所以我们可以随时的unlock解锁，以免锁住太长时间
		cout<<"取出一个元素"<<command<<endl;
	}
}


//把收到的信息（玩家命令）入到一个队列的线程
void inMsgRecvQueue()
{
	for(int i=0;i<10000;++i)
	{
		cout<<"插入一个元素"<<i<<endl;
		std::unique_lock<std::mutex> sbguard1(my_mutex);
		msgRecvQueue.push_back(i);  //直接把数字塞进队列
		
		my_cond.notify_one();  //尝试把wait()的线程唤醒，执行完这行，那么outMsgRecvQueue()里的wait()会被唤醒。
		//其它处理
	}
	return;
}