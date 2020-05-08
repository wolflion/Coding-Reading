## chap03C++与数据抽象

### 3.1、类概念基础

+ 类的一些重要特征：
  + 访问属性private，protected，public
  + 静态和非静态成员函数的原型以及数据成员的声明
  + 可以包含其中的另一个类（嵌套类）的声明
+ TIntStack类的示例

```cpp
class TIntStack{
public:
    //Member Functions
    //Default Constructor
    TIntStack(unsigned int stackSize = DEFAULT_SIZE);
    TIntStack(const TIntStack& that); //copy constructor
    //Assignment Operator
    TIntStack& operator=(const TIntStack& assign);
    ~TIntStack();//Destructor
    void Push(int thisValue);
    int Pop();
    unsigned int HowMany() const;
    //add many more member functions
private:
    //Data Members
    int* _sp;
    unsigned _count;
    unsigned _size;
};
```



### 3.2、类元素细节

#### 3.2.1、访问区域

+ public区域仅仅看见成员函数。

#### 3.2.2、分析

### 3.3、复制构造函数

+ `Tingstack s2=s1;`//因为非内置类型需要复制构造函数，不能跟`int i=j;`
+ 复制构造函数的声明：`TIntStack(TIntStack& source)`

```cpp
int j;
int k(j); //This is as good as int k = j;
char*p("ABCD"); //as good as char*p = "ABCD";
```

#### 3.3.1、访问对象的数据成员--C++模型

### 3.4、赋值运算符

+ `a = b;//Assign one stack to another`
+ 对于任何赋值运算符，必须注意几件事情：
  + （1）确保我们没有将对象赋给它本身（如a=a）
  + （2）重新使用被赋值对象中的资源或删除它
  + （3）从源对象上复制任何需要复制的东西到目的对象
  + （4）最后，返回对目的对象的引用

### 3.5、this指针和名称修正的进一步说明

### 3.6、const成员函数的概念

### 3.7、编译器实现const成员函数的方式