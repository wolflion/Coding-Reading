/*
 * ��4.3����ʮ��������ת���ɶ����ƻ�ʮ���������֡�
 */

#include <iostream>
using namespace std;

int flag = 1;//check: n/d == 0

//ת������
void trans_num(int n, int d)
{
	int mod;
	mod = n%d;  //n��ʾ���֣�d��ʾ���ƣ�շת���
	n = n/d;
	while (flag && n) //flagΪ0�Ĳ�����ת��
	{
		trans_num(n, d);
	}
	flag = 0;
	switch (mod)
	{
	case 10:
		cout << "A";
		break;
	case 11:
		cout << "B";
		break;
	case 12:
		cout << "C";
		break;
	case 13:
		cout << "D";
		break;
	case 14:
		cout << "E";
		break;
	case 15:
		cout << "F";
		break;
	default:
		cout << mod;
	}
}

//������
int main()
{
	int n, d;
	cout << "��������n�ͽ���d:" << endl;
	cin >> n >> d;
	trans_num(n, d);
	cout << endl;
}

/*
 * ���룺234 2
 * �����11101010
 */

//֧��16�������ϵ�ת����ֱ��ת�����ַ���Ȼ�����Ȩ���㡿
void trans_num01(int n, int d)
{
	int mod;
	mod = n%d;
	n = n / d;
	while (flag && n)
	{
		trans_num(n, d);
	}
	flag = 0;
	if (mod >= 10)
	{
		mod = mod - 10 + 65;//ת�����ַ�
	}
	else
	{
		mod = mod + 48;
	}
	cout << mod;//����ַ�
}