#include <iostream>
using namespace std;

// 定义一个函数模板
template <typename T>
void TempFun(T a){
	cout << a <<endl;
}

int main(){
	TempFun(1);  // 1 实例化为TempFun<const int>(1)
	TempFun("1"); // 1 实例化为TempFun<const char *>("1")
}

//其它场景
void DefParm(int m = 3) {}  // C++98编译通过，C++11编译通过
template <typename T = int>
	class DefClass{};  // C++98编译通过，C++11编译通过
template <typename T = int>
	void DefTempParm() {};  // C++98编译失败，C++11编译通过

// g++ 2-11-1.cpp