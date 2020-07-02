#include <iostream>
using namespace std;

struct Base
{
	virtual void Func(){}
	virtual ~Base(){}
};

struct DerivedB : Base
{
	void Func() override
	{
		cout << "call func in DerivedB" << endl;
	}
};

struct DerivedC : Base
{
	void Func() override
	{
		cout << "call func in DerivedC" << endl;
	}
};

struct DerivedD : Base
{
	void Func() override
	{
		cout << "call func in DerivedD" << endl;
	}
};

class A
{
public:
	A(Base* interface) :m_interfaceB(interfaceB)
	{

	}
	void Func()
	{
		m_interfaceB->Func();
	}
	~A()
	{
		if (m_interfaceB != nullptr)
		{
			delete m_interfaceB;
			m_interfaceB = nullptr;
		}
	}
private:
	Base* m_interfaceB;
};

int main()
{
	A *a = new A(new DerivedB);
	a->Func();

	delete a;
	return 0;
}