#include <string>
#include <unordered_map>
#include <memory>
#include <functional>
using namespace std;
#include <Any.hpp>
#include <NoCopyable.hpp>

class IocContainer : NonCopyable
{
public:
	IocContainer(void){}
	~IocContainer(void) {}

	template<class T, typename Depend, typename... Args>
	void RegisterType(const string& strKey)
	{
		//通过闭包擦除了参数类型
		std::function<T* (Args...)> function = [](Args... args){return new T(new Depend(args...)); };
		RegisterType(strKey, function);
	}

	template<class T, typename... Args>
	T* Resolve(const string& strKey, Args... args)
	{
		if (m_creatorMap.find(strKey) == m_creatorMap.end())
		{
			return nullptr;
		}
		Any resolver = m_creatorMap[strKey];
		std::function<T* (Args...)> function = resolver.AnyCast<std::function<T*(Args...)>>();
		
		return function(args...);
	}

	template<class T,typename... Args>
	std::shared_ptr<T> Resolve(const string& strKey, Args... args)
	{
		T* t = Resolve<T>(strKey, args...);
		return std::shared_ptr<T>(t);
	}
private:
	void RegisterType(const string& strKey, Any constructor)
	{
		if (m_creatorMap.find(strKey) != m_creatorMap.end())
		{
			throw std::invalid_argument("this key has already exist!");
		}
		//通过Any擦除了不同类型的构造器
		m_creatorMap.emplace(strKey, constructor);
	}

private:
	unordered_map<string, Any> m_creatorMap;
};