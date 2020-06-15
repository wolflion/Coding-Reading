#include <iostream>
using namespace std;

class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent" << endl;
	}
private:
	int a;
};

class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}
	void print()
	{
		cout << "Parent" << endl;
	}
private:
	int a;
};

int main()
{
	cout << sizeof(Parent1) << endl; //8
	cout << sizeof(Parent2) << endl; //4
	system("pause");
	return 0;
}