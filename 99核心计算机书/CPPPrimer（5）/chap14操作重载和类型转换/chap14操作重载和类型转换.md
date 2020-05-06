## chap14操作重载和类型转换

### 14.1、基本概念

+ `data1 + data2` 等价于`operator+(data1, data2);`，都调用了非成员函数`operator+`
+ `data1 += data2` 等价于`data1.operator+(data1, data2);`，都调用了成员函数`operator+=`  **赋值类的只能定义为成员函数**。
+ 哪些该定义为成员函数，哪些该定义为非成员函数？

### 14.2、输入和输出运算符（必须是非成员函数）

#### 14.2.1、重载输出运算符<<

```cpp
ostream& operator<<(ostream& os, const Sales_data &item)
{
    os<<item.isbn()<<" "<<item.units_sold<< " "<<item.revenue<<" "<<item.avg_price();
    return os;
}
```

#### 14.2.2、重载输入运算符>>

```cpp
istream& operator>>(istream& is,Sales_data &item)
{
    double price;
    is >> item.bookNo >>item.units_sold>>price;
    if(is) //检查输入是否成功
        item.revenue = item.units*sold*price;
    else
        item = Sales_data();//输入失败，对象被赋予默认的状态
    return is;
}
```

### 14.3、算术和关系运算符

### 14.4、赋值运算符

### 14.5、下标运算符（必须是成员函数）

+ 最好能提供两个版本
  + 一个返回普通引用
  + 一个是类的常量成员并且返回常量引用

```cpp
class StrVec{
public:
    std::string& operator[](std::size_t n)
    {
        return elements[n];
    }
    const std::string& operator[] (std::size_t n) const
    {
        return elements[n];
    }
private:
    std::string *elements; //指向数组首元素的指针
};
```

### 14.6、递增和递减运算符

### 14.7、成员访问运算符

+ 解引用运算符（`*`）和箭头运算符（`->`）

```cpp
class StrBlobPtr{
public:
    std::string& operator*()const
    {
        auto p = check(curr,"dereference past end");
        return (*p)[curr];  //(*p)是对象所指的vector
    }
    std::string* operator->()const
    {
        //将实际工作委托给解引用操作符
        return &this->operator*();
    }
}
```

### 14.8、函数调用运算符

+ 例子：运算符负责返回其参数的绝对值

```cpp
struct absInt{
    int operator()(int val)const{
        return val < 0? -val:val;
    }
}

//调用
int i=-42;
absInt absObj; //含有函数调用运算符的对象
int ui = absObj(i);//把i传递给absObj.operator()
```

+ 如果类定义了调用运算符，则该类的对象称作**函数对象（function object）**，也叫**仿函数**。

#### 14.8.1、lambda是函数对象

#### 14.8.2、标准库定义的函数对象

#### 14.8.3、可调用对象与function

### 14.9、重载、类型转换与运算符

#### 14.9.1、类型转换运算符

+ 例子：

```cpp
class SmallInt{
public:
    SmallInt(int i=0):val(i)
    {
        if(i<0 || i>255)
            throw std::out_of_range("Bad SmallInt value");
    }
    operator int() const {return val;}
private:
    std::size_t val;
};
```

+ C++11引入了**显示式类型转换运算符（explicit conversion operator）**

```cpp
//SmallInt中用了explict的关键字
//operator int() const {return val;}
SmallInt si=3;//正确：构造函数不是显式的
si + 3;//错误，需要隐式类型转换，但类的运算符是显式的
static_cast<int>(si)+3;//正确，显式地请求类型转换
```

#### 14.9.2、避免有二义性的类型转换

#### 14.9.3、函数匹配与重载运算符

### ReadMe

+ 20200506晚上加班看了会儿，整理了第一稿，具体细节还未看，真是融合了《More Effective C++》，《C++11》的知识啊，当然还有操作符重载的基本知识。
  + 让我串起了**仿函数（函数对象）**，`std::function`，`static_cast`与`explict`的搭配用法。