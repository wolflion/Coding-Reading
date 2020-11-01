//7-2使用非默认的容器（list或vector）作为基础容器构造stack并测试它

#include<iostream>
#include<vector>
#include<list>
#include<stack>  // 使用stack容器适配器需要包含此文件
using namespace std;

int main()
{
	//使用list或vector作为栈的容器
	stack<int, list<int>>a;
	stack<int, vector<int>>b;
	int i;
	//压入数据
	for ( i = 0; i < 10; i++)
	{
		a.push(i);
		b.push(i * 2);
	}

	cout << "栈的大小:" << endl;
	cout << "a:" << a.size() << " b:" << b.size() << endl << endl;

	//将数据弹出栈并显示它
	cout << "由堆栈a出栈的数据:" << endl;
	while (!a.empty())
	{
		cout << " " << a.top();
		a.pop();
	}
	cout << endl << endl;

	//将数据弹出栈并显示它
	cout << "由堆栈b出栈的数据:" << endl;
	while (!b.empty())
	{
		cout << " " << b.top();
		b.pop();
	}
	cout << endl;

	return 0;
}