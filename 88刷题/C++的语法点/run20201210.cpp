#include<iostream>
using namespace std;

/*
* 1、两个##的作用   【C++中##的作用】https://blog.csdn.net/qq_34793133/article/details/80489686
*/

#define LOGSTRINGS(fm, ...) printf(fm,__VA_ARGS__) 

#define CONCAT(B)  B##_D  //只有前面的是可以换的？后面的不行？

class A_D
{
public:
	A_D()
	{
		cout << "A_D" << endl;
	}
};

class B_D
{
public:
	B_D()
	{
		cout << "B_D" << endl;
	}
};

class A4
{};

int main()
{
	CONCAT(A) a1;  // 扩展到A_D
	CONCAT(B) b1;  // 扩展到B_D

	cout << __FUNCTION__ <<":"<< __LINE__ << endl;

	// https://blog.csdn.net/zhangkai19890929/article/details/82392300?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromBaidu-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromBaidu-1.control
	LOGSTRINGS("hello, %d ", 10);  //https://blog.csdn.net/bat67/article/details/77542165

}