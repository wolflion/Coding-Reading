#include <map>
#include <mutex>
#include <thread>

using namespace std;

//线程入口函数
void myprint(int iNum)
{
	cout<<"线程编程="<<iNum<<endl;
	return;
}

int main()
{
	// 一、创建和等待多个线程  【可以用同一个线程入口函数】
	
	vector<thread> mythreads;
	//创建10个线程，线程入口函数统一调用myprint
	for(int i=0;i<10;i++)
	{
		mythreads.push_back(thread(myprint,i));//创建并开始10个线程，他们已经开始执行了
	}
	
	for(auto iter=mythreads.begin();iter!=mythreads.end();++iter)
	{
		iter->join(); //等待10个线程都返回
	}
	
	cout<<"I love china!"<<endl;  //执行到这句，退出
}