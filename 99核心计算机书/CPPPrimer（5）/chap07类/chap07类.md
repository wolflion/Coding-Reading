## chap07、类

+ 0
  + 类的基本思想是**数据抽象（data abstraction）和封装（encapsulation）**。数据抽象是一种依赖于**接口（interface）和实现（implementation）**分离的编程（以及设计）技术。
  + 类的接口：包括用户所能执行的操作
  + 类的实现：包括类的数据成员、负责接口实现的函数体以及定义类所需的各种私有函数。
  + **封装**实现了类的接口和实现的分离。

### 7.1、定义抽象数据类型

+ 我们不能访问Sales_item对象的数据成员，事实上，我们根本不知道这个类有哪些数据成员。【chap1】

#### 7.1.1、设计Sales_data类

+ 0
  + Sales_data的接口应该包含以下操作：
    + 一个isbn成员函数，用于返回对象的ISBN编号
    + 一个read函数，将数据从istream读入到Sales_data对象中
    + 一个print函数，将Sales_data对象的值输出到ostream
+ 使用改进的Sales_data类

```cpp
Sales_data total;//保存当前求和结果的变量
if(read(cin, total)) //读入第一笔交易
{
    Sales_data trans;  //保存下一条交易数据的变量
    while(read(cin,trans)) //读入剩余的交易
    {
        if(total.isbn() == trans.isbn())//检查isbn
            total.combine(trans);//更新变量total当前的值
        else
        {
            print(cout,total) << endl; //输出结果
            total = trans;  //处理下一本书
        }
    }
   printf(cout,total)<<endl; //输出最后一条交易
}
else  //没有输入任何信息
{
    cerr<<"No data?!"<<endl;  //通知用户
}
```



#### 7.12、定义改进的Sales_data类

+ 0

```cpp
struct Sales_data{
    //新成员：关于Sales_data对象的操作
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    //数据成员和2.6.1节相比没有改变
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
//Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
```



+ 定义成员函数
  + 尽管所有成员都必须在类的内部声明，但成员函数体可以定义在类内也可以定义在类外。
+ 引入this
  + 成员函数通过一个名为this的额外的隐式参数来访问调用它的那个对象。
  + this是一个常量指针，我们不允许改变this中保存的地址
+ 引入const成员函数
  + *这个还跟this有关？*
+ 类作用域和成员函数
  + 成员函数体可以随意使用类中的其他成员而无须在意这些成员出现的次序。
+ 在类的外部定义成员函数
+ 定义一个返回this对象的函数

```cpp
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;//把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this;  //返回调用该函数的对象
}
```

#### 7.1.3、定义类相关的非成员函数

+ 0
  + 定义一些辅助函数，尽管这些函数定义的操作从概念上来说属于类的接口的组成部分，但它们实际上并不属于类本身。
+ 定义read和print函数

```cpp
//输入的交易信息包括ISBN，售出总数和售出价格
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >>price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn()<<" "<<item.units_sold<< " "
        <<item.revenue<<" " <<item.avg_price();
    return os;
}
```



+ 定义add函数

```cpp
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; //把lhs的数据成员拷贝给sum
    sum.combine(rhs);//把rhs的数据成员加到sum当中
    return sum;
}
```

#### 7.1.4、构造函数

+ 0
  + 每个类都分别定义了它的对象被初始化的方式，类通过一个或几个特殊的成员函数来控制其对象的初始化过程，这些函数叫做**构造函数**。任务是：**初始化类对象的数据成员**，无论何时只要类的对象被创建，就会执行构造函数。
+ 合成的默认构造函数
  + **编译器创建的构造函数**又被称为合成的默认构造函数（synthesized default constructor）
+ 某些类不能依赖于合成的默认构造函数
+ 定义Sales_data的构造函数

```cpp
struct Sales_data{
    //新增的构造函数
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(p*n) {}
    Sales_data(std::istream &);
    //之前已有的其他成员
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
}
```



+ =default的含义
  + `Sales_data() = default;`，该构造函数不接受任何实参，所以它是一个默认构造函数。
+ 构造函数初始值列表
+ 在类的外部定义构造函数

#### 7.1.5、拷贝、赋值和析构

+ 0
+ 某些类不能依赖于合成的版本
  + **当类需要分配类对象之外的资源时，合成的版本常常会失效**。

### 7.2、访问控制与封装

+ 0
+ 使用class或struct关键字

#### 7.2.1、友元

+ 0
+ 友元的声明

### 7.3、类的其他特性

#### 7.3.1、类成员再探

#### 7.3.2、返回*this的成员函数

#### 7.3.3、类类型

#### 7.3.4、友元再探

### 7.4、类的作用域

#### 7.4.1、名字查找与类的作用域

### 7.5、构造函数再探

#### 7.5.1、构造函数初始值列表

#### 7.5.2、委托构造函数

#### 7.5.3、默认构造函数的作用

#### 7.5.4、隐式的类类型转换

#### 7.5.5、聚合类

#### 7.5.6、字面值常量类

### 7.6、类的静态成员

## ReadMe