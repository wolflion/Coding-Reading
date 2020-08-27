// spec.cpp
// 程序清单8.5：函数模板特化举例

#include <iostream>
#include <string.h>  // 标准C
#include <string>
using namespace std;

template <class T>
size_t bytes(T& t)
{
	cout << "(using primary template)\n";
	return sizeof t;
}

size_t bytes(char*& s)
{
	cout << "(using char* overload)\n";
	return strlen(s) + 1;
}

//template<>
//size_t bytes<wchar_t*>(wchar_t*& w)   // 这个原书写法有问题，自己改的；
size_t bytes(wchar_t*& w)
{
	cout << "(using wchar_t* specialization)\n";
	return 2*(wcslen(w) + 1);
}

template<>
size_t bytes<>(string& s)
{
	cout << "(using string explicit specialization)\n";
	return sizeof s;
}

template<>
size_t bytes<float>(float& x)
{
	cout << "(using string explicit specialization)\n";
	return sizeof x;
}

int main()
{
	int i;
	cout << "bytes in i:"<<bytes(i)<<endl;
	char *s = "hello";
	cout << "bytes in s:" << bytes(s) << endl;
	wchar_t *w = L"goodbye";
	cout << "bytes in w:" << bytes(w) << endl;
	string t;
	cout << "bytes in t:" << bytes(t) << endl;
	float x;
	cout << "bytes in x:" << bytes(x) << endl;
	double y;
	cout << "bytes in y:" << bytes(y) << endl;

	getchar();
	return 0;
}

/*在VS2013上编译成功，也输出了，准备到unix环境上看下*/