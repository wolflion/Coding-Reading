## auto类型推导

### 1、auto的新含义

+ 在C++98/03中`auto`是**局部变量**，与`static`关键字相对。
+ C++11中`auto`的新功能是**类型推导**
  + **使用auto声明的变量必须马上初始化**，让编译器推断出它的类型，同时在编译时将auto占位符替换为真正的类型（即分配空间）。
+ 深刻理解以下代码

```cpp
auto x = 5;
auto pi = new auto(1);
const auto *v = &x,u = 6;
static auto y = 0.0;
auto int r;
auto s;
```

### 2、auto的推导规则

+ 1、当不声明为指针或引用时，auto的推导结果和初始化表达式抛弃引用和**cv限定符（const和volatile限定符的统称）**后类型一致。
+ 2、当声明为指针或引用时，auto的推导结果将保持初始化表达的cv属性。
+ 关联知识：**auto的推导和函数模板参数的自动推导有相似之处**。
+ 深刻理解以下代码

```c++
int x = 0;
auto *a = &x; //auto 推导为int
auto b = &x; //auto被推导为int*
auto &c = x; //auto被推导为int
auto d = c;  //auto被推导为int

const auto e = x;  //e ->const int
auto f = e;  //f ->int

const auto &g = x;  //e ->const int &
auto &h = g; //f ->const int&
```

### 3、auto的限制

+ 1、auto不能用于函数参数
+ 2、auto不能用于非静态成员变量
+ *这部分理解得不够深刻，毕竟只是看，没有在项目中实践过呢*

### 4、什么时候用auto

+ 1、迭代器的定义中，省略STL容器的类型

```c++
std::map<double,double>resultMap;
std::map<double,double>::iterator it = resultMap.beign();//原来的写法
auto it = resultMap.begin();//现在的写法
```

+ 2、*待理解的新场景*

## ReadMe

+ 1、20200420第1版：参考《深入应用C++11》1.1.1的内容
  + 第3部分内容不太理解；第4部分只理解了4.1。