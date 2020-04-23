## decltype

### 0、课前秀

+ 获取表达式的“声明类型”（Declared Type），所以命名为**`decltpe`**
+ 思考：**typeid与decltype的异同**
  + `typeid`用于返回指针或引用所指对象的实际类型。

### 1、获知表达式的类型

+ **在编译时推导出一个表达式的类型**，参考`sizeof`
+ 理解以下代码

```cpp
int x = 0;
decltype(x) y = 1;  //y -> int
decltype(x+y) z = 0; //z->int

const int& i = 1;
decltype(i) j = y; //j -> const int &

const decltype(z) *p = &z;  //*p -> const int, p->const int *
decltype(z)* pi = &z;  // *pi ->int, pi->int*
decltype(pi)* pp = &pi; // *pp ->int*, pp->int**
```

### 2、decltype的推导规则

+ 规则1：exp是标识符、类访问表达式，decltype(exp)和exp的类型一致。
  + `int i = 0; decltype(i) x = 0;`
+ 规则2：exp是函数调用，decltype(exp)和返回值的类型一致
  + `int add(int ,int );  decltype(add());`
+ 规则3：其它情况，若exp是一个左值，则decltype(exp)是exp类型的左值引用，否则和exp类型一致。

```cpp
struct Foo {int x;};
decltype(foo.x) a = 0; // a->int
// 左值就是左值引用，右值，就是原类型
decltype((foo.x)) b = a; // b->const int &  
```

### 3、decltype的实际应用

+ *初学，体会不深*
+ *作者讲得例子理解不深*，但我倒想到一个例子，sum(T1 x, T2 y)，返回值到底用哪个的问题，现在可以类型推导了。

### 4、其它知识点

+ **使用decltype进行推导时，其成员不会继承const或volatile限制符**。

### 5、总结

+ 在非泛型编程中，我们不用对类型进行推导，因为任何表达式中变量的类型都是明确的，而运算、函数调用等也都有明确的返回类型。**在泛型编程中，类型成了未知数**。
  + `add (T a1, Y a2);//两个不同的类型，add()的返回值类型怎么写？`在这种情况下产生了类型推导。
+ decltype和auto异同

## ReadMe

+ 1、 20200421第1版：参考《深入应用C++11》1.1.2的内容
  + 第3节“实际应用”理解得不深 