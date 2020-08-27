// partial.cpp
// 程序清单8.7 类模板的部分特化举例
#include <iostream>
using namespace std;
template<class T,class U>
class A
{
public:
	A() {
		cout << "primary template\n";
	}
};

template<class T, class U>
class A<T*, U>
{
public:
	A() {
		cout << "<T*,U> partial specialization\n";
	}
};

template<class T>
class A<T, T>
{
public:
	A() {
		cout << "<T,T> partial specialization\n";
	}
};

//template<class T,U>  //这个又错了，我自己注释掉，改的才行了
template<class U>
class A<int, U>
{
public:
	A() {
		cout << "<int,U> partial specialization\n";
	}
};

int main()
{
	A<char, int>a1;
	A<char*, int>a2;
	A<float, float>a3;
	A<int,float>a4;
	getchar();
	return 0;
}
