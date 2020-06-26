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

//业务函数
void f(Location p)
{
	cout << p.GetX() << endl; 
	//这个时候，会调用p的析构函数，因为p的生命周期没有了
}

void playobj()
{
	//这里有3个构造函数，3个析构函数【输出看看】
	Location a(1, 2);
	Location b = a;

	f(b);//b这个实参去初始化形参p，会调用拷贝构造函数
}


int main(int argc, char** argv)
{
	playobj();//这个时候打印得更直观

	getchar();
	return 0;
}
