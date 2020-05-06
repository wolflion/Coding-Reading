## 18shared_ptr共享的智能指针

### 0、课前秀

+ 智能指针不会担心内存泄漏的问题，会自动删除分配的内存。
+ **智能指针**是存储指向动态分配（堆）对象指针的类，用于生存期控制，能够确保在离开指针所在作用域时，自动正确地销毁动态分配的对象，防止内存泄漏。
+ 提供3种智能指针，引用头文件`<memory>`
  + std::shared_ptr
  + std::uniq_ptr
  + std::weak_ptr
+ **[shared_ptr]( https://zh.cppreference.com/w/cpp/memory/shared_ptr )是个类**，要用类的思维去学它，不是个关键字。

### 1、shared_ptr原理介绍

+ `std::shared_ptr`使用引用计数，每一个shared_ptr的拷贝都指向相同的内存。
+ 在最后一个shared_ptr析构的时候，内存才会被释放。

### 2、shared_ptr的基本用法 

#### 2.1、初始化

+ 代码

```cpp
std::shared_ptr<int> p(new int(1));
std::shared_ptr<int> p2 = p;
//reset方法来初始化
std::shared_ptr<int> ptr;
ptr.reset(new int(1));
if(ptr)
{
    cout<<"ptr is not null";
}
```

#### 2.2、获取原始指针

```cpp
std::shared_ptr<int> ptr(new int(1));
int* p = ptr.get();
```

#### 2.4、指定删除器

+ 一般写法

```cpp
void DeleteIntPtr(int* p)
{
    delete p;
}
std::shared_ptr<int> p(newint,DeleteIntPtr);
```

+ lambda表达式写法

`std::shared_ptr<int> p(new int,[](int* p){delete p;});`

### 3、使用shared_ptr需要注意的问题

+ 不要用一个原始指针初始化多个shared_ptr
+ 不要在函数实参中创建shared_ptr。
+ 通过`shared_from_this()`返回this指针。
+ 要避免循环引用

## ReadMe

+ 20200506整理完第一版，《深入应用C++》4.1。
  + *事实上有点稀里糊涂的，没有主动把知识串起来的感觉*