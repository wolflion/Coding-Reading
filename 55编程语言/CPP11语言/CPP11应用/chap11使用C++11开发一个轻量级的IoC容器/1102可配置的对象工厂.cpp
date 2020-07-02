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

	//ע����Ҫ��������Ĺ��캯������Ҫ����һ��Ψһ�ı�ʶ���Ա��ں��洴������ʱ�������
	template<class Drived>
	void RegisterType(string strKey)
	{
		std::function<T*()> function = []{return new Drived(); };
		RegisterType(strKey, function);
	}

	//����Ψһ�ı�ʶȥ���Ҷ�Ӧ�Ĺ�������������ָ�����
	T* Resolve(string strKey)
	{
		if (m_creatorMap.find(strKey) == m_creatorMap.end())
		{
			return nullptr;
		}
		std::function<T*()> function = m_creatorMap[strKey];
		retrun function();
	}

	//��������ָ�����
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

//���Դ���
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

//������  Bus::test()  Car::test()