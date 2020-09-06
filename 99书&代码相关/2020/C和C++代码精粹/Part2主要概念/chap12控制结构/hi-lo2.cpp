// 程序清单12.8 把外部的循环控制从程序清单 12.2中删除
// hi-lo2.cpp：移动外部布尔标志
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	cout << "Think of a number between 1 and 100.\n"
		<< "If you don't cheat. I'll figure it out\n"
		<< "in seven guesses or less!"
		<< endl;

	for (;;)// 无限循环的习惯用法
	{
		int lo = 1, hi = 100;
		char response;
		int guess;
	}

	// 开始游戏
	while (lo <= hi)
	{
		// 得到guess的值
		guess = (lo + hi) / 2;
		cout << "Is it " << guess << "(L/H/Y): " << endl;
		cin >> response;
		response = toupper(response);

		// 缩小查找范围：
		if (response == 'L')
		{
			lo = guess + 1;
		}
		else if (response == 'H')
		{
			hi = guess - 1;
		}
		else if (response != 'Y')
		{
			cout << "What? Try again..." << endl;
		}
		else
			break;
	}

	// 打印结果：
	if (lo > hi)
	{
		cout << "You cheated!" << endl;
	}
	else
	{
		cout << "Your number was " << guess << endl;
	}

	cout << "Wanna play again? " << endl;
	cin >> response;
	if (toupper(response) != 'Y')
		break;
	}
}