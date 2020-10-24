#include <thread>

using namespace std;

void myprint(const int &i, char *pmybuf)
{
	cout<<i<<endl;
	cout<<pmybuf<<endl;
	return;
}

int main()
{
	// 一、传递临时对象作为线程参数
	int myvar = 1;
	int &myary = myvar;
	char mybuf[] = "this is a test!";
	thread myobj(myprint,myvar,mybuf);//第1个函数数，后面是函数的参数。  【查看内存的地方发现：**这里不是个真引用，是个值**】
	//myobj.join();
	myobj.detach(); // 子线程和主线程分别执行【这里有个引用,myvar是个引用，对应的资源会被回收】
	cout<<"I love china!"<<endl;
	
	return 0;
	
}