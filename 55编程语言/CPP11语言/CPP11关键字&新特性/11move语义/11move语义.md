## move语义

### 0、课前秀

+ 这个概念不是很懂，但看cppreference里分为了两种：移动构造，移动赋值
  + [move constructors]( https://zh.cppreference.com/w/cpp/language/move_constructor )
  + [move assignment]( https://zh.cppreference.com/w/cpp/language/move_assignment )
+ 移动语义是通过右值来匹配临时的，**普通的左值能否借助移动语义来优化性能**。
+ 这是[std::move]( https://zh.cppreference.com/w/cpp/utility/move )的链接，来自于头文件`<utility>`

### 1、std::move

+ std::move将左值转换为右值。**只是将对象的状态或者的有权从一个对象转移到另一个对象，只是转移，没有内存拷贝**。
+ 体会一下图2-1：深拷贝与move的区别
+ move将一个左值强制转换为一个右值引用，**为了方便实现移动构造**。
+ 当一个对象内部有较大的堆内存或者动态数组时，很有必要写move语义的拷贝构造函数和赋值函数，避免无谓的深拷贝，以提高性能。
+ 基本类型（int,char[10]）使用move，仍然会发生拷贝（因为没有对应的移动构造函数），**move对于含资源的对象来说更有意义**。
+ 深拷贝例子

```cpp
A& A::operator=(const A& rhs)
{
    //销毁m_ptr指向的资源
    //复制rhs.m_ptr所指的资源，并使用m_ptr指向它
}
```

+ 无须深拷贝

```cpp
A& A::operator=(const A&& rhs)  //A&&，是右值引用啊，跟move没啥关系吧？
{
    //转移资源的控制权，无须复制
}
```

## ReadMe

+ 20200428第1版，《深入应用C++11》2.2
  + 知道了使用场景，但例子写得不太清楚，自已再找其它书来补充一下吧