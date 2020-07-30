struct Object{
	virtual void fun() = 0;
};

struct Base : public Object{
	void fun() final;  // 声明为final
};

struct Derived : public Base{
	void fun();  // 无法通过编译
};

// g++ -c -std=c++11 2-10-2.cpp