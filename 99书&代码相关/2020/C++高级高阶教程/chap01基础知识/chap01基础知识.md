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

+ 1、用const修饰的变量的值一定是不能改变的。**有些情况下，可以更改常变量的值**
+ 2、常引用或常指针，只能指向常变量。*引用被声明为常引用（或指针被声明为指向常量的指针），只是说明不能通过该引用（或该指针）云修改被引用对象（或被指向单元）的值。
+ 修改const的值，Program 1.3-6.cpp

```cpp
#include <iostream>
using namespace std;
int main()
{
    int i = 5;
    const int &ri = i;
    cout << ri << endl; //5
    int *p = &i;
    *p = 6;
    cout << ri << endl;//6
}
```

### 1.4、const_cast的用法 （20/398）

+ `const_cast`是**C++运算符**，作用是去除复合类型中的const或volatile属性。
+ 变量本身的const属性是不能去掉的。要想修改常变量的值，一般是去除指向该变量的指针（或引用）的const属性。
+ Program 1.4-1.cpp

```cpp
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void ConstTest1(){
    const int a = 5;
    int *p;
    p = const_cast<int*>(&a);  //如果写成p = &a;则发生编译错误
    (*p)++;
    cout<<a<<endl<<endl;  //**5，但实际上a的值已经变成6了** 编译器在优化代码时，把a替换成了文字常量5
}

void ConstTest2(){
    int i;
    cout<<"please input a integer:";
    cin>>i;
    const int a = i;
    int &r = const_cast<int&>(a); //如果写成int &r = a;则发生编译错误
    r++;
    cout<<a<<endl;//6	**常变量a无法转化成对应的文字常量**
}
```

+ 使用const_cast进行类型转换时要注意以下几点：
  + （1）const_cast操作符的语法形式：`const_cast<type>(expression)`，其中expression外面的括号不能省略。
  + （2）通过const_cast操作符，只能将`const type*`类型转换成`type*`类型
  + （3）一个变量本身被定义为只读变量（常变量），那么它永远是常变量。**const_cast取消的是对间接引用时的改写限制（即只针对指针或引用），而不能改变变量本身的const属性**。
  + （4）传统的C语言中的强制类型转换，也可以将`const type*`类型转换成`type*`类型

### 1.5、mutable的用法 （22/398）

+ Program1.5-1.cpp

```cpp
#include <iostream>
#include <string>
using namespace std;
class Student{
    string Name;
    int times_of_getname;
public:
    Student(char* name){
        Name = name;
        times_of_getname = 0;
    }
    string get_name(){
        times_of_getname++;
        return Name;
    }
    void PrintTimes(){
        cout<<times_of_getname<<endl;
    }
};

int main()
{
    const Student s("张三");
    cout<<s.get_name()<<endl; //**常量对象s，调用了类Student中的非const函数get_name()
    cout<<s.get_name()<<endl;
    s.PrintTimes();
}
```

+ **`mutable`关键字就是用来解决常函数中不能修改对象的数据成员的问题**。如果在某些情况下，希望在常函数中仍然可以修改某个成员变量的值，那么就在该成员变量的声明前面加上关键字mutable。
+ Program1.5-2.cpp

```cpp
#include <iostream>
#include <string>
using namespace std;
class Student{
    string Name;
    mutable int times_of_getname;//在需要修改的成员变量前加关键字mutable
public:
    Student(char* name){
        Name = name;
        times_of_getname = 0;
    }
    string get_name() const{
        times_of_getname++;//尽管是在常函数中，用mutable声明的变量仍然可以修改
        return Name;
    }
    void PrintTimes(){
        cout<<times_of_getname<<endl;
    }
};

int main()
{
    const Student s("张三");
    cout<<s.get_name()<<endl; //**常量对象s，调用了类Student中的非const函数get_name()
    cout<<s.get_name()<<endl;
    s.PrintTimes();
}
```

+ 关键字mutable，要注意以下几点：
  + （1）mutable只能作用于类的非静态和非常量数据成员
  + （2）mutable关键字提示编译器该变量可以被类的const函数修改
  + （3）在一个类中，用mutable修饰的变量只能是少数，或者根本不使用mutable，大量使用表示程序有缺陷。

### 1.6、求余运算符 （24/398）

### 1.7、sizeof的用法（25/398）

+ **sizeof是一种在编译时进行的运算，而与运行时无关**。当sizeof的参数是变量或表达式时，**sizeof运算真正关心的是变量或表达式的类型**。

### 1.8、引用与指针常量（28/398）

### 1.9、左值的概念（32/398）

+ 凡是可以出现在赋值运算左边的表达都是**左值**，出现在赋值运算右边的表达式都是**右值**。**左值一定可以作为右值**，而反过来不一定成立。
+ 值为可寻址的非只读单元的表达式称为**左值**。理解左值的概念，注意：
  + （1）左值一定是可以寻址的表达式。（表达式3+5是一个符号常量表达式，它不能被寻址，因此就不能作为左值）
  + （2）

### 1.10、关于goto语句

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