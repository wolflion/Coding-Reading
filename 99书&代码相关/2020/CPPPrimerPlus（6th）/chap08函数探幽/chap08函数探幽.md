## chap08、函数探幽  262（281/971）

### 8.1、C++内联函数

### 8.2、引用变量

### 8.3、默认参数

### 8.4、函数重载

### 8.5、函数模板

+ 0、建立一个交换模板：

```cpp
template <typename AnyType>  //C++98之前，typename是用class代替的
void Swap(AnyType &a, AnyType &b)
{
    AnyType temp;
    temp = a;
    a = b;
    b = temp;
}
```

+ 程序清单8.11 funtemp.cpp，功能是：using a function template。

#### 8.5.1、重载的模板

+ 原来模板的特征标为`(T &, T &)`，新模板的特征标为`(T [], T [], int)`。**最后一个参数的类型为具体类型(int)**。
+ twotemps.cpp

#### 8.5.2、模板的局限性

+ 编写的模板函数很可能无法处理某些类型
+ **为特定类型提供具体化的模板定义**

#### 8.5.3、显式具体化

+ 1、
+ 2、显式具体化示例 程序清单 8.13 twoswap.cpp

#### 8.5.4、实例化和具体化

#### 8.5.5、编译器选择使得哪个函数

#### 8.5.6、模板函数的发展

+ 1、是什么类型
  + `void ft(T1 x, T2 y)  {xpy = x+y;} //会不知道xpy是啥类型，到底是T1还是T2类型？`
+ 2、关键字decltype（C++11）
  + `decltype(x+y) xpy = x+y;`。**语法格式`decltype(expression) var;`**
+ 3、另一种函数声明语法（C++11后置返回类型）

### 8.6、总结

### 8.7、复习题

### 8.8、编程练习