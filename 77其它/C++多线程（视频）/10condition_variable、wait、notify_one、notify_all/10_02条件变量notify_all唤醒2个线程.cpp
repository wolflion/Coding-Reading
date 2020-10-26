

int main()
{
	//创建2个线程
	A myobja;//A是类
	std::thread myOutnMsgObj(&A::outMsgRecvQueue,&myobja);
	std::thread myOutnMsgObj2(&A::outMsgRecvQueue,&myobja);
	std::thread myInMsgObj(&A::InMsgRecvQueue,&myobja);
	
	myInMsgObj.join();
	myOutMsgObj2.join();
	myOutMsgObj.join();
}