
#include <thread>
using namespace std;

//自己创建的线程也要从一个函数开始
void myprint()
{
	// 我自己想的，如果这个地方 sleep(60)
	cout<<"my thread start"<<endl;
	cout<<"my thread end"<<endl;
}

// 主线程从main()开始执行，我们自己创建的线程，也需要从一个函数开始运行（初始函数），一旦这个函数运行完毕，就代表着我们这个线程，运行结束。
int main()
{
	thread mythreadobj(myprint);  // thread是标准类里的类   【myprint是可调用对象】
	mythreadobj.join();//让主线程等子进程执行完毕  【当子线程执行完毕，主线程再往下走】
	cout<<"I love china!"<<endl;
	
	return 0;
}