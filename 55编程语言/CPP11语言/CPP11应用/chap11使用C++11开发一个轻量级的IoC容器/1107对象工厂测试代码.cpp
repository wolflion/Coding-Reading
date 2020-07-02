struct Base
{
	virtual void Func(){}
	virtual ~Base(){}
};

struct DerivedB : public Base
{
	DerivedB(int a, double b) :m_a(a), m_b(b)
	{

	}
	void Func() override
	{
		cout << m_a + m_b << endl;
	}
private:
	int m_a;
	double m_b;
};

struct DerivedC : public Base
{

};

struct A
{
	A(Base* ptr) :m_ptr(ptr)
	{

	}

	~A()
	{
		if (m_ptr != nullptr)
		{
			delete m_ptr;
			m_ptr = nullptr;
		}
	}

private:
	Base* m_ptr;
};

void TestIoc()
{
	IocContainer ioc;
	ioc.RegisterType<A, DerivedC>("C");
	auto c = ioc.ResolveShared<A>("C");

	//注册时要注意DerivedB的参数int和double
	ioc.RegisterType<A, DerivedB, int, double>("C");
	auto b = ioc.ResolveShared<A>("C", 1, 2.0);//还要传入参数
	b->Func();
}

//输出结果 3