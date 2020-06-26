#include <iostream>
using namespace std;

class Location
{
public:
	Location(int xx = 0, int yy = 0)
	{
		X = xx;
		Y = yy;
		cout << "Constructor Object.\n";
	}

	//copy构造函数，完成对象的初始化
	Location(const Location& obj)
	{
		X = obj.X;
		Y = obj.Y;
	}

	~Location()
	{
		cout << X << "," << Y << "Object destroyed" << endl;
	}

	int GetX()
	{
		return X;
	}

	int GetY()
	{
		return Y;
	}
protected:
private:
	int X, Y;
};


//g函数，返回一个元素
Location g()
{
	//这里面执行了两层构造函数
	Location A(1, 2);
	return A;  //这个时候会执行一下 拷贝构造函数；【创建了一个匿名对象】
}

//这个时候，会产生一个匿名对象
void objplay()
{
	g();//匿名对象没人用，所以就析构了。
}

int main(int argc, char** argv)
{
	objplay();   //画个图，入栈的方式
	getchar();
	return 0;
}