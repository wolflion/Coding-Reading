#include<iostream>
using namespace std;

//����һ��������
struct TestClass
{
	int xx;
	TestClass(int x)
	{
		xx = x;
		cout << "�������xx=" << xx << endl;
	}

	~TestClass()
	{
		cout << "��������xx=" << xx << endl;
	}
};


int main()
{
	//ʹ��ȫ��operator new����һ���ܴ��4��TestClass�����ڴ��
	TestClass* bp = (TestClass*)::operator new(sizeof(TestClass) * 4);

	//���ڴ����ʹ��placement new����һ������
	TestClass* p1 = bp;
	new(p1)TestClass(100);

	//��ʽ����TestClass�����������ٶ���
	p1->~TestClass();

	//�����������������ڶ�������
	TestClass* p2 = p1 + 1;   //���������⣬ָ��ԭ�з���ĵ�ַ�ϡ�
	new(p2)TestClass(200);  // ���ʣ�����ֵ��һ�������е���죬�ѵ�����ֵ���ã�
	p2->~TestClass();

	//�ͷ��ڴ��
	::operator delete(bp);
	return 0;
}