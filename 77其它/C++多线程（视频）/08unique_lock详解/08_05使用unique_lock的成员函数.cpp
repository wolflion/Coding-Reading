

//相当于把sbguard1和my_mutex绑定在一起了
std::unique_lock<std::mutex> sbguard1(my_mutex,std::defer_lock);  //没有加锁的my_mutex

if(sbguard1.try_lock()==true)
{
	//访问共享数据，
}
else
{
	//没拿到锁
	cout<<"没拿到锁"<<endl;
}

sbguard1.lock(); //不用管解锁的问题了，unique_lock类会自动解锁

//但是unique_lock也提供了一个unlock()方法，比如sbguard1.unlock();
msgRecvQueue.push_back(i);