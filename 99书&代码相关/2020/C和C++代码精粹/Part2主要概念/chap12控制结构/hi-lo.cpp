// �����嵥12.2 Hi-lo��C++����
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

	bool done = false;  // ѭ�����Ʊ���
	while (!done)
	{
		char response;
		int guess;

		// ����Ϸ��
		bool found = false;  // ѭ�����Ʊ���

		int lo = 1, hi = 100;
		while (!found && lo <= hi)
		{
			// ���guess
			guess = (lo + hi) / 2;
			cout << "Is it " << guess << "(L/H/Y): " << endl;
			cin >> response;
			response = toupper(response);

			// ��С���ҷ�Χ��
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

		// ��ӡ�����
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