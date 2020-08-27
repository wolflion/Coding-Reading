// spec2.cpp
// 程序清单8.6  类模板特化举例
#include <iostream>
using namespace std;

template<typename T>
class A
{
public:
	A(){
		cout << "primary\n";
	}
};

template<>   // 这个又少一行，我自己加的
class A<char>
{
public:
	A(){
		cout << "char specialization\n";
	}
};

template<>
class A<float>
{
public:
	A(){
		cout << "float specialization\n";
	}
};

int main()
{
	A<int>a1;
	A<char>a2;
	A<float>a3;
	getchar();
	return 0;
}