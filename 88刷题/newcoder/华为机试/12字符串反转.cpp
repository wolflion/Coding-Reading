#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;

    //原来还可以这样；
	string s(str.rbegin(),str.rend());

    // 还是用了迭代器
	for (std::string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
		std::cout << *rit;
	return 0;
}


// 为什么这个不行？
#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::string s1; 
	cin >> s1;

	string s = s1;

	for (string::reverse_iterator it = s.rend(); it != s.rbegin(); it++)
	{
		cout << *it;
	}
	return 0;
}
#endif