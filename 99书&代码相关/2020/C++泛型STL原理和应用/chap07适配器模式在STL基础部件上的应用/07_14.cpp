// ��7-14����remove_if����֤greater_1����ȷ��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// һԪ����������
template <typename _Tp>
struct greater_1 :public binary_function<_Tp, _Tp, bool>
{
	_Tp value; //����
	greater_1(_Tp v)   //���캯��
	{
		value = v;
	}

	bool operator()(const _Tp& __x)const
	{
		return __x > value;
	}
};


int main()
{
	//����һ����������ʼ��
	vector<int> Vect{ 900,100,20,300,4,200,250 };
	//��ʾ������ʼ�����
	cout << "��ʾ������ʼ�����" << endl;
	for_each(Vect.begin(), Vect.end(), [](int n)
		{
			cout << ' ' << n;
		});

	cout << endl << endl;
	vector<int>::iterator it;

	//�Ƴ����������д���100��Ԫ��
	it = remove_if(Vect.begin(), Vect.end(), greater_1<int>(100));

	// ��ʾ�Ƴ���������������
	cout << "�Ƴ�������Ӧ�ñ�������Ϊ��" << endl;
	
	for_each(Vect.begin(), Vect.end(), [](int n)
		{cout << ' ' << n; });

	return 0;
}