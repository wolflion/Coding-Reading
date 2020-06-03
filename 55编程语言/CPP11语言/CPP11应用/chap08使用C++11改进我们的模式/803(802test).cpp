#include <iostream>
#include <string>
using namespace std;

struct A
{
	A(const string&)
	{
		cout << "lvalue" << endl;
	}
	A(string&& x)
	{
		cout << "rvalue" << endl;
	}
};

struct B
{
	B(const string&)
	{
		cout << "lvalue" << endl;
	}
	B(string&& x)
	{
		cout << "rvalue" << endl;
	}
};

struct C
{
	C(int x, double y)
	{
		//
	}
	void Fun()
	{
		cout << "test" << endl;
	}
};

int main()
{
	string str = "bb";
	//����A���͵ĵ���
	Singleton<A>::Instance(str);
	//����B���͵ĵ�������ʱ����str��move֮������ֵ��Ȼ����Ը����ƶ����������⸴��
	Singleton<B>::Instance(std::move(str));
	//����C���͵ĵ���������������
	Singleton<C>::Instance(1, 3.14);
	//��ȡ���������õ�������ķ���
	Singleton<C>::GetInstance()->Fun();

	//�ͷŵ���
	Singleton<A>::DestroyInstance();
	Singleton<B>::DestroyInstance();
	Singleton<C>::DestroyInstance();
}