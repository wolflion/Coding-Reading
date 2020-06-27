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
//结论1：函数的返回值是一个元素（复杂类型的）。【C++编译器，就这么设计的】，
//A是临时对象，返回的是一个新的匿名对象（所以会调用匿名对象类的copy构造函数)

//结论2：有关匿名对象的去和留
//如果用匿名对象初始化另外一个同类型的对象，那么匿名对象直接转成有名对象
//如果用匿名对象 赋值给 另外一个同类型的对象，匿名对象 马上被析构

//你这么写代码，设计编译器的大牛们：我就给你返回一个新对象（没有名字，匿名对象）。
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

void objplay3()
{
	//结论：把匿名对象 直接初始化m。【此时C++编译器 直接把匿名对象转成m，（扶正），从匿名转成有名字m了】
	Location m = g(); 
	cout << "匿名对象被扶正，不会被析构" << endl;
	cout << m.GetX() << endl;//只会调用一次析构函数
}

void objplay4()
{
	//用匿名对象 赋值给m2后，匿名对象被析构
	Location m2(1,2);
	m2 = g(); //匿名对象会析构
	cout << "匿名对象，被析构" << endl;
	cout << m2.GetX() << endl;
}

int main(int argc, char** argv)
{
	objplay();   //画个图，入栈的方式
	getchar();
	return 0;
}