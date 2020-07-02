#include <string>
#include <map>
#include <memory>
#include <functional>
using namespace std;

template <class T>
class IocContainer
{
public:
	IocContainer(void)
	{

	}

	~IocContainer(void)
	{

	}

	//注册需要创建对象的构造函数，需要传入一个唯一的标识，以便在后面创建对象时方便查找
	template<class Drived>
	void RegisterType(string strKey)
	{
		std::function<T*()> function = []{return new Drived(); };
		RegisterType(strKey, function);
	}

	//根据唯一的标识去查找对应的构造器，并创建指针对象
	T* Resolve(string strKey)
	{
		if (m_creatorMap.find(strKey) == m_creatorMap.end())
		{
			return nullptr;
		}
		std::function<T*()> function = m_creatorMap[strKey];
		retrun function();
	}

	//创建智能指针对象
	std::shared_ptr<T> ResolveShared(string strKey)
	{
		T* ptr = Resolve(strKey);
		return std::shared_ptr<T>(ptr);
	}

private:
	void RegisterType(string strKey, std::function<T*()> creator)
	{
		if (m_creatorMap.find(strKey) != m_creatorMap.end())
		{
			throw std::invalid_argument("this key has already exist!");
		}
		m_creatorMap.emplace(strKey, creator);
	}

private:
	map<string, std::function<T*()>> m_creatorMap;
};

//测试代码
struct ICar
{
	virtual ~ICar(){}
	virtual void test() const = 0;
};

struct Bus : ICar
{
	Bus(){};
	void test()const { std::cout << "Bus::test()"; }
};

struct Car : ICar
{
	Car(){};
	void test()const { std::cout << "Car::test()"; }
};

int main()
{
	IocContainer<ICar> carioc;
	carioc.RegisterType<Bus>("bus");
	carioc.RegisterType<Car>("car");

	std::shared_ptr<ICar> bus = carioc.ResolveShared("bus");
	bus->test();
	std::shared_ptr<ICar>car = carioc.ResolveShared("car");
	car->test();
	return 0;
}

//输出结果  Bus::test()  Car::test()