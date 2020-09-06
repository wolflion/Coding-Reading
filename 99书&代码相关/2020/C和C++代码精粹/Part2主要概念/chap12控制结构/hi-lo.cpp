// 程序清单12.2 Hi-lo的C++程序
// hi-lo.cpp
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	cout << "Think of a number between 1 and 100.\n"
		<< "If you don't cheat. I'll figure it out\n"
		<< "in seven guesses or less!"
		<< endl;

	bool done = false;  // 循环控制变量
	while (!done)
	{
		char response;
		int guess;

		// 玩游戏：
		bool found = false;  // 循环控制变量

		int lo = 1, hi = 100;
		while (!found && lo <= hi)
		{
			// 获得guess
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
				found = true;
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
		done = toupper(response) != 'Y';
	}
}