## chap5、数组与指针（186/398）

### 5.1、数组名的意义

+ **数组名的本质**是数组最开始的那个元素的首地址，**而且是地址常量**。
+ Program5.1-1.cpp

```cpp
#include<iostream>
using namesapce std;
int main()
{
    int A[4]={1,2,3,4};
    int B[4]={5,6,7,8};
    int (&rA)[4] = A;
    cout<<A<<endl;
    cout<<&A<<endl;
    cout<<A+1<<endl;
    cout<<&A+1<<endl;
    cout<<B<<endl;
    cout<<rA<<endl;
    cout<<&rA<<endl;
}
```

### 5.2、什么是指针

### 5.3、数组与指针的关系

+ 两者一些重要的差异

  + （1）数组的空间是静态分配的
  + （2）数组名代表的是一个指针常量（Program5.3-1.cpp）
  + （3）就算不用“*”而是用“[]”进行说明，函数形参中的“数组”仍然是指针。（Program5.3-2.cpp）
  + （4）如果函数的形参是数组实参的引用，那么数组的长度被作为类型的一部分。
  + （5）在概念上，指针同一维数组相对应。而将多维数组当做一维数组看待时，可以有多种不同的分解方式。
  + （6）字符数组和字符指针虽然在形式上很接近，但在内存空间的分配和使用上还是有重大差别。（Program5.3-7.cpp）

### 5.4、数组的初始化

  + *电子书少了1页*

  + 如果数组的元素是对象，那么在初始化的时候会调用对象的构造函数。

### 5.5、多维数组与多重指针

  + Program5.5-1.cpp

### 5.6、成员数据指针

### 5.7、关于this指针

  + this用在类的非静态成员函数内部，**代表当前对象的首地址**。
  + this指针实际上在对象的构造函数中就可以使用了。（Program5.7-1.cpp）

  ```cpp
  #include<iostream>
  using namespace std;
  extern class A *pA;
  class A{
  public:
      A(){pA = this;}
      virtual void show(){cout<<"in A"<<endl;}
  };
  
  class B:public A{
      int i;
  public:
      B(){i=5;}
      void show(){
          cout<<"in B"<<endl;
          cout<<"i="<<i<<endl;
      }
  };
  
  A *pA;
  int main()
  {
      B b;
      pA->show();
  }
  /*
  in B
  i=5
  */
  ```

### 5.8、什么是悬挂指针

+ 指针所指向的内存地址，如果不能被当前的程序合法地访问，那么这个指针就是一个**“悬挂指针”**。出现悬挂指针的最典型情形就是在定义指针变量之后没有对它进行初始化。（Program5.8-1.cpp）

```cpp
#include<iostream>
using namespace std;
int main()
{
    int *p;
    cout<<*p<<endl;  //p是一个典型的悬挂指针
}
```

+ 更隐藏的悬挂指针（Program5.8-2.cpp）

```cpp
#include<iostream>
using namespace std;
class A{
    int num;
    int *p;
public:
    void show()
    {
        cout<<*p<<endl;
    }
};

int main()
{
    A a; //构造函数中没有对p进行初始化，会成为悬挂指针
    a.show();
}
```

+ 为了防止悬挂指针带来的危害，应注意以下几点：
  + （1）、C++引入了“引用”机制，由于引用在定义的同时就必须初始化。
  + （2）、如果一定要使用指针，要养成在定义指针变量的同时对它进行初始化的习惯。
    + 初始化为NULL
    + 指向一个有名变量
    + new运算为其申请空间，要规划好何时使用delete。
    + 如果某个类的成员是指针，那么应该要在类的构造函数中对它进行初始化。

### 5.9、什么是解引用

+ 在对指针解引用时，要注意这样几点：
  + （1）在对指针解引用之前，必须保证指针不是一个空指针或悬挂指针，否则会引起运行时错误。

### 5.10、指针与句柄

+ **句柄**一般是指获取另一个对象的方法。**目的就是建立起与被访问对象之间的唯一的联系**。
+ 对指针的不当操作会引发一些运行时错误。

## ReadMe

+ 20200602看了第1遍。