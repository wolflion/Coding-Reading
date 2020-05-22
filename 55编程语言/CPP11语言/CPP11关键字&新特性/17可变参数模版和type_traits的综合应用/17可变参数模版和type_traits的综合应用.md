## 17、可变参数模版和type_traits的综合应用

### 0、课前秀

+ 可变参数模板，经常与lambda、function、type_traits结合在一起。

### 1、optional的实现

+ C++14中将包含一个`std::optional`类。
+ optional可以用于解决函数返回无效值的问题。如果查找不到对象，就会返回一个无效值，这不表明函数执行失败，而是表明函数正确执行了，只是结果不是有用的值。
+ *需要自已用C++11实现一个optional*
+ C++17支持了[`std::optional`]( https://zh.cppreference.com/w/cpp/utility/optional )

### 2、惰性求值类lazy的实现

+ *C#中支持*
+ 惰性求值类实现思路：借助lambda表达式，将函数封装到lambda表达式中，而不是马上求值，需要的时候再调用。
+ C++11实现的Lazy.cpp

```cpp
#include<Optional.hpp>
template<typename T>
struct Lazy{
    Lazy(){}
    //保存需要延迟执行的函数
    template<typename Func, typename... Args>
    Lazy(Func& f, Args && ... args)
    {
    	m_func = [&f, &args...]{return f(args...);};
    }
    //延迟执行，将结果放到option1中缓存起来，下次不用重新计算可以直接返回结果
    T& Value()
    {
        if(!m_value.IsInit())
        {
            m_value = m_func();
        }
        return *m_value;
    }
    
    bool IsValueCreated() const
    {
        return m_value.IsInit();
    }
private:
    std::function<T()>m_func;
    Optional<T> m_value;
};

template<class Func, typename... Args>
Lazy<typename std::result_of<Func(Args...)>::type>
    Lazy(Func && func, Args && ... args)
{
    return Lazy<typename
        std::result_of<Func(Args...)>::type>(std::forward<Func>(fun),std::forward<Args>(args)...);
}
```



### 3、dll帮助类

+ 实现的关键是如何将一个FARPROC变成一个函数指针复制给std::function，然后再调用可变参数执行。

### 4、lambda链式调用

+ *关于链式调用，比较典型的例子是C#中的linq*
+ 链式调用要实现的目的是，将多个函数按照前一个的输出作为下一个输入串起来，然后再推迟到某个时刻计算。
+ PPL中的链式调用.cpp

```cpp
int main()
{
    auto t = create_task([]() ->int
                         {
                             return 0;
                         }
                        );
    //Create a lambda that increments its input value.
    auto increment = [](int n){return n + 1;};
    
    //Run a chain of continuations and print the result.
    int result = t.then(increment).then(increment).then(increment).get();
    wcout<<result<<endl;
    //output 3
}
```

### 5、any类的实现

### 6、function_traits

#### 6.1、实现function_traits的关键技术

+ 实现function_traits关键是要**通过模板特化和可变参数模板来获取函数类型和返回类型**。

#### 6.2、function_traits的实现

### 7、variant的实现

+ variant类似于union，它能代表定义的多种类型，允许赋不同类型的值给它。

#### 7.1、打造variant需要解决的问题

+ （1）要在内部定义一个内存对齐的缓冲区
+ （2）要解决赋值的问题

#### 7.2、打造variant的关键技术

+ （1）找出最大的typesize来构造一个内存对齐的缓冲区
+ （2）类型检查和缓冲区中创建对象

#### 7.3、取值问题

### 8、ScopeGuard

+ ScopeGurard的作用是确保资源面对非正常返回时总能被成功释放。

### 9、tuple_helper

## ReadMe

+ 20200522匆忙看完第1遍，没啥紧急的活，就学会儿了，就是get了些概念。