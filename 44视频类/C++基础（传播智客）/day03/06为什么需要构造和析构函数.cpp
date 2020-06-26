#include <iostream>
using namespace std;

class Test4
{
public:
	void init(int _a, int _b)
	{
		a = _a;
		b = _b;
	}
protected:
private:
	int a;
	int b;
};

int main(int argc, char** argv)
{
	Test4 t0601;//类没有提供构造函数，C++编译器会自动给你提供一个默认的构造函数
	            //类没有提供拷贝构造函数，C++编译器会自动给程序员提供一个 默认的copy构造函数

	t0601.init(3, 4);

	Test4 tArray[3];//没办法进行初始化，只能对元素本身
	tArray[0].init(1, 2);

	//还有一种
	Test4 t21; t21.init(1, 2);
	Test4 t22; t22.init(1, 2);
	Test4 t23; t23.init(1, 2);
	//这种场景下，显式的初始化方案，就显得很蹩脚了 
	Test4 tArrayOther[3] = { t21, t22, t23 };

	Test4 t[1999];//这种情况，这很难满足了。

	getchar();
	return 0;
}