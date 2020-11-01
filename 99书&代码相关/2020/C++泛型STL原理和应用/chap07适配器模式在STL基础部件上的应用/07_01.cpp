// 7-1 使用STL提供的stack适配器并用默认的deque构成栈并测试
#include<iostream>
#include<deque>
#include<stack>  // 使用stack容器适配器需要包含此文件
using namespace std;

int main()
{
	deque<int> mydeque(3, 100); //创建具有3个元素 初始值100的队列
	stack<int> Mystack1;
	stack<int> Mystack2(mydeque); //创建一个栈用mydeque对其初始化   【**这是适配器的精华？**】

	cout << "size of Mystack1:" << (int)Mystack1.size() << endl;  // 0
	cout << "size of Mystack2:" << (int)Mystack2.size() << endl;   // 3

	Mystack1.push(200);
	Mystack1.push(300);
	Mystack1.push(400);
	Mystack1.push(500);
	Mystack1.push(600);

	Mystack2.pop();

	cout << Mystack2.top() << endl;  //显示Mystack2的栈顶数据

	cout << "size of Mystack1:" << (int)Mystack1.size() << endl;  //5
	cout << "size of Mystack2:" << (int)Mystack2.size() << endl;  //2
	return 0;
}