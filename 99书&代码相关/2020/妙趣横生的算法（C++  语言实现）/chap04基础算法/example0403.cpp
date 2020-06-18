/*
 * 例4.3、将十进制数字转换成二进制或十六进制数字。
 */

#include <iostream>
using namespace std;

int flag = 1;//check: n/d == 0

//转换函数
void trans_num(int n, int d)
{
	int mod;
	mod = n%d;  //n表示数字，d表示进制，辗转相除
	n = n/d;
	while (flag && n) //flag为0的不进行转换
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

//主函数
int main()
{
	int n, d;
	cout << "输入数字n和进制d:" << endl;
	cin >> n >> d;
	trans_num(n, d);
	cout << endl;
}

/*
 * 输入：234 2
 * 输出：11101010
 */

//支持16进制以上的转换【直接转换成字符，然后进行权运算】
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
		mod = mod - 10 + 65;//转换成字符
	}
	else
	{
		mod = mod + 48;
	}
	cout << mod;//输出字符
}