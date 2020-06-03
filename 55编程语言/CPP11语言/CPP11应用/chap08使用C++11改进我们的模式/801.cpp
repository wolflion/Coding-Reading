//代码清单8-1：支持0~6个参数的单例

template<typename T>
class Singleton
{
public:
	//支持0个参数的构造函数
	static T* Instance()
	{
		if (m_pInstance == nullptr)
			m_pInstance = new T();
		return m_pInstance;
	}

	//支持1个参数的构造函数
	template<typename T0>
	static T* Instance(T0 arg0)
	{
		if (m_pInstance == nullptr)
			m_pInstance = new T(arg0);
		return m_pInstance;
	}

	//支持2个参数的构造函数
	template<typename T0,typename T1>
	static T* Instance(T0 arg0,T1 arg1)
	{
		if (m_pInstance == nullptr)
			m_pInstance = new T(arg0,arg1);
		return m_pInstance;
	}

	//支持3个参数的构造函数
	template<typename T0, typename T1,typename T2>
	static T* Instance(T0 arg0, T1 arg1,T2 arg2)
	{
		if (m_pInstance == nullptr)
			m_pInstance = new T(arg0, arg1, arg2);
		return m_pInstance;
	}

	//支持4个参数的构造函数
	template<typename T0, typename T1,typename T2,typename T3>
	static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3)
	{
		if (m_pInstance == nullptr)
			m_pInstance = new T(arg0, arg1,arg2,arg3);
		return m_pInstance;
	}

	//支持5个参数的构造函数
	template<typename T0, typename T1, typename T2, typename T3,typename T4>
	static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
	{
		if (m_pInstance == nullptr)
			m_pInstance = new T(arg0, arg1, arg2, arg3, arg4);
		return m_pInstance;
	}

	//支持6个参数的构造函数
	template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
	static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
	{
		if (m_pInstance == nullptr)
			m_pInstance = new T(arg0, arg1, arg2, arg3, arg4, arg5);
		return m_pInstance;
	}

	//获取单例
	static T* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			throw std::logic_error("the instance is not init, please initialize the instance first");
		}
		return m_pInstance;
	}

	//释放单例
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
private:
	//不允许复制和赋值
	Singleton(void);
	virtual ~Singleton(void);
	Singleton(const Singleton&);
	Singleton& operator = (const Singleton&);
private:
	static T* m_pInstance;
};

template<class T> T* Singleton<T>::m_pInstance = nullptr;

//测试代码
struct A
{
	A(){}
};

struct B
{
	B(int x){}
};

struct C
{
	C(int x, double y){}
};

int main()
{
	//创建A类型的单例
	Singleton<A>::Instance();

	//创建B类型的单例
	Singleton<B>::Instance(1);

	//创建C类型的单例
	Singleton<C>::Instance(1,3.14);

	Singleton<A>::DestroyInstance();
	Singleton<B>::DestroyInstance();
	Singleton<C>::DestroyInstance();
}