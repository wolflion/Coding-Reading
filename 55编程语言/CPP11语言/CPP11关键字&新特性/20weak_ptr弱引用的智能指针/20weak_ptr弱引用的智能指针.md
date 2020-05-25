## 20、weak_ptr弱引用的智能指针

### 0、课前秀

+ 弱引用指针weak_ptr是用来监视shared_ptr的，不会使引用计数加1，它不管理shared_ptr内部的指针，主要是为了监视shared_ptr的生命周期。
+ weak_ptr没有重载操作符`*`和`->`，因为它不共享指针，不能操作资源。
+ weak_ptr还可以用来返回this指针和解决循环引用的问题。

### 1、weak_ptr基本用法 

+ （1）通过use_count()方法来获得当前观测资源的引用计数

```cpp
shared_ptr<int> sp(new int(10));
weak_ptr<int> wp(sp);

cout<<wp.use_count()<<endl; //结果将输出1
```

+ （2）通过expired()方法来判断所观测的资源是否已经被释放

```cpp
shared_ptr<int> sp(new int(10));
weak_ptr<int> wp(sp);
if(wp.expired())
	std::cout << "weak_ptr无效，所监视的智能指针已被释放\n";
else
	std::cout << "weak_ptr有效\n";
//结果将输出：weak_ptr有效
```

+ （3）通过lock方法来获取所监视的shared_ptr

```cpp
std::weak_ptr<int> gw;
void f()
{
    if(gw.expired()) //所监视的shared_ptr是否释放
    {
        std::cout << "gw is expired\n";
    }
    else
    {
        auto spt = gw.lock();
        std::cout << *spt << "\n";
    }
}

int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        f();
    }
    f();
}

/*
输出：
42
gw is expired
*/
```

### 2、weak_ptr返回this指针

+ 代码

```cpp
struct A: public std::enable_shared_from_this<A>
{
    std::shared_ptr<A> GetSelf()
    {
        return shared_from_this();
    }
    ~S()
    {
        cout<<"A is deleted"<<endl;
    }
};
std::shared_ptr<A> spy(new A);
std::shared_ptr<A> p = spy->GetSelf();//OK
/*
输出结果
A is deleted
*/
```

+ 

### 3、weak_ptr解决循环引用问题

+ 代码

```cpp
struct A;
struct B;
struct A{
    std::shared_ptr<B> bptr;
    ~A() {cout<<"A is deleted!"<<endl;}
};

struct B{
    std::shared_ptr<A> aptr;//将A B中的任何一个改成 weak_ptr
    ~B() {cout<<"B is deleted!"<<endl;}
};

void TestPtr()
{
    {
        std::shared_ptr<A> ap(new A);
        std::shared_ptr<B> bp(new B);
        ap->bptr = bp;
        bp->aptr = ap;
    }//Objects should be destroyed
}
```



+ 

## ReadMe

+ 20200525上班期间开了个头，看了一点点，晚上回来后整理起来的，基本没有串起的，只是个记录，后面再看呢。