//7-2ʹ�÷�Ĭ�ϵ�������list��vector����Ϊ������������stack��������

#include<iostream>
#include<vector>
#include<list>
#include<stack>  // ʹ��stack������������Ҫ�������ļ�
using namespace std;

int main()
{
	//ʹ��list��vector��Ϊջ������
	stack<int, list<int>>a;
	stack<int, vector<int>>b;
	int i;
	//ѹ������
	for ( i = 0; i < 10; i++)
	{
		a.push(i);
		b.push(i * 2);
	}

	cout << "ջ�Ĵ�С:" << endl;
	cout << "a:" << a.size() << " b:" << b.size() << endl << endl;

	//�����ݵ���ջ����ʾ��
	cout << "�ɶ�ջa��ջ������:" << endl;
	while (!a.empty())
	{
		cout << " " << a.top();
		a.pop();
	}
	cout << endl << endl;

	//�����ݵ���ջ����ʾ��
	cout << "�ɶ�ջb��ջ������:" << endl;
	while (!b.empty())
	{
		cout << " " << b.top();
		b.pop();
	}
	cout << endl;

	return 0;
}