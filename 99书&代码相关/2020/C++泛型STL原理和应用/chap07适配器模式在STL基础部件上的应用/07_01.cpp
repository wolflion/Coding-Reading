// 7-1 ʹ��STL�ṩ��stack����������Ĭ�ϵ�deque����ջ������
#include<iostream>
#include<deque>
#include<stack>  // ʹ��stack������������Ҫ�������ļ�
using namespace std;

int main()
{
	deque<int> mydeque(3, 100); //��������3��Ԫ�� ��ʼֵ100�Ķ���
	stack<int> Mystack1;
	stack<int> Mystack2(mydeque); //����һ��ջ��mydeque�����ʼ��   ��**�����������ľ�����**��

	cout << "size of Mystack1:" << (int)Mystack1.size() << endl;  // 0
	cout << "size of Mystack2:" << (int)Mystack2.size() << endl;   // 3

	Mystack1.push(200);
	Mystack1.push(300);
	Mystack1.push(400);
	Mystack1.push(500);
	Mystack1.push(600);

	Mystack2.pop();

	cout << Mystack2.top() << endl;  //��ʾMystack2��ջ������

	cout << "size of Mystack1:" << (int)Mystack1.size() << endl;  //5
	cout << "size of Mystack2:" << (int)Mystack2.size() << endl;  //2
	return 0;
}