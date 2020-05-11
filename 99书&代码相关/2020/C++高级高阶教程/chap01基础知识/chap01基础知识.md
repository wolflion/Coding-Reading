## chap01、基础知识

### 1.1、关于C++标准

+ 可以用`and, or, not, bitand, bitor, compl,xor, and_eq, or_eq, xor_eq, not_eq`来代替逻辑运算符`&&, ||, !=`。
+ **这些是C99引入的，并不是新关键字，而是用宏替换实现的**，打开文件`iso646.h`
+ progrm1.1-1.cpp

```cpp
#include <iostream>
#include <iso646.h>
using namespace std;
int main(){
    int i=5,j=6,k=7;
    if(i<j and j<k) cout<<"i<j and j<k"<<endl;
    if(i<j or j<k) cout<<"i<j or j<k"<<endl;
}
```

### 1.2、文字常量和常变量   12/398

+ 常量：直观地理解成“值不可改变的量”。在C++中，常量分两种：
  + 文字常量（literal constant）：**“符号常量”，经编译之后写在代码区，是不可寻址的**
  + 常变量（const variable）：**跟其它变量一样，分配空间，是可以寻址的**。
+ 文字常量一般是：**静态数组名、枚举常量、全局（静态变量）首地址**。（不可寻址，值不可变）
+ Program1.2-1.cpp

```cpp
#include <iostream>
using namespace std;
void ShowValue(const int& i){
    cout<<i<<endl;
}

int main()
{
    const int j=5;
    int *ptr;
    void *p = (void*)&j;
    ptr = (int*)p;
    (*ptr)++;
    ShowValue(j);  //程序输出6,const的值被改变了
}
```

+ **将常变量理解成“只读”变量会更准确一些**。

+ Program

### 1.3、const的用法 （14/398）

#### （1）const的位置

+ 位置比较灵活。一般来说，除了修饰一个类的成员函数外，const不会出现在一条语句的最后。
+ const的例子--Program1.3-1.cpp 

```cpp
#include <iostream>
using namespace std;
int main(){
    int i = 5;
    const int v1=1;
    int const v2 = 2;
    const int *p1;
    int const *p2;
    //以下三条语句都会编译错误，为什么？
    //const* int p3;
    //int* const p3 = &v1;
    //int* const p3;
    int* const p3 = &i;
    const int* const p4 = &v1;
    int const* const p5 = &v2;
    const int &r1 = v1;
    int const &r2 = v2;
    //以下语句会报编译错误，为什么？
    //const & int r3;
    //以下语句会报警告，并忽略const
    int& const r4 = i;
    cout <<*p4<<endl;
}
```



#### （2）const对象和对象的const成员

#### （3）用const修饰函数的参数和函数的返回值

#### （4）常见的对const的误解

### 1.4、const_cast的用法 （20/398）

### 1.17、explicit的用法（58/398）

+ explicit关键字的作用：**禁止隐式调用类的单参数的构造函数**。
  + 一、禁止隐式调用拷贝构造函数
  + 二、禁止类对象之间的隐式转换
+ 隐式调用单参数构造函数的例子 Program1.17-1.cpp

```cpp
#include <iostream>
using namespace std;
class A{
    int num;
public:
    A(){num = 0;}
    A(int num){this->num = num;}
    A(const A &a){num = a.num;}
    friend void show(const A &a);
};

void show(const A &a){
    cout<<a.num<<endl;
}

int main(){
    A a1 = 37;
    A a2 = a1;
    show(a1);
    show(a2);
    show(47);	
}
//输出是 37 37 47
```

+ 禁止隐式调用单参数构造函数的例子 Program1.17-2.cpp

```cpp
#include <iostream>
using namespace std;
class A{
    int num;
public:
    A(){num = 0;}
    explicit A(int num){this->num = num;}
    explicit A(const A &a){num = a.num;}
    friend void show(const A &a);
};

void show(const A &a){
    cout<<a.num<<endl;
}

int main(){
    A a1(37);//A a1 = 37;  
    A a2(a1);//A a2 = a1;
    show(a1);
    show(a2);
    show(A(47));//show(47);	
}
//输出是 37 37 47
```

+ explict关键字的，要注意的几点：
  + （1）explicit关键字只需用于单参数的构造函数前面。
  + （2）如果想禁止类A对象被隐式转换为类B对象，可以在类B中使用关键字explicit。`explict B(A a){...}` 或者 `explict B(const A &a){...}`

## ReadMe

+ 2020511看了（1.1，1.2，1..17），1.3看了一点点