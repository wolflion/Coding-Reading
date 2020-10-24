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
	thread myobj(myprint,myvar,mybuf);//第1个函数数，后面是函数的参数。
	myobj.join();
	cout<<"I love china!"<<endl;
	
	return 0;
	
}