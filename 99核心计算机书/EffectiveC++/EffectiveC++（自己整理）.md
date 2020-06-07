## 内容

### Part01、Accustoming Yourself to C++

#### Itm01：View C++ as a federation of languages

+ C
+ Object-Oriented C++
+ Template C++
+ STL
+ *不知道C++11，C++20的特性会不会再加大这个区分*

#### Item02： Perfer consts, enums,and inlines to #define

+ `#define`时**宏名有可能并未记入符号表**。

#### Item03：Use const whenever possible

+ **const在`*`号左边，物是常量；const 在`*`号右边，指针是常量**
  + `const char* p = greeting;//const data`
  + `char* const p = greeting;//const pointer`
+ 迭代器中也有这样的区分
  + `::const_iterator` **迭代器所指的东西不可被改动**。
+ const成员函数
  + 是不是只能const成员函数，调用const对象？
  + const成员函数和非const成员函数，如何重载？
+ **显式加上`mutable`关键字**

#### Item04：Make sure that objects are initialized before they're used

+ 内置类型的初始化？
+ 自定义类型的初始化？
+ 内置类型的（local,static）的初始化不同。