## chap03、字符串、常量和数组

### 3.1、命名空间的using声明

### 3.2、标准库类型string

#### 3.2.1、定义和初始化string对象

#### 3.2.2、string对象上的操作

#### 3.2.3、处理string对象中的字符

### 3.3、标准库类型vector

+ 0
  + vector是模板而非类型。

#### 3.3.1、定义和初始化vector对象

+ 0
  + **表3.4：初始化vector对象的方法**
+ 列表初始化vector对象
  + `vector<string> articles  = {"a", "an", "the"};`
+ 创建指定数量的元素
  + `vector<int> ivec(10,-1);//10个int类型的元素，每个都被初始化为-1`
+ 值初始化

#### 3.3.2、向vector对象中添加元素

#### 3.3.3、其他vector操作

### 3.4、迭代器介绍

+ 0
  + 所有标准库容器都可以使用迭代器，但是其中只有少数几种才同时支持下标操作符。
  + **严格来说，string对象并不属于容器类型**。
  + 迭代器提供了对对象的间接访问。

#### 3.4.1、使用迭代器

+ 0
  + **end指向尾元素的下一个元素**。
+ 迭代器运算符
  + **表3.6：标准容器迭代器的运算符**。

```cpp
string s("some string");
if(s.begin() != s.end()) { // 确保s非空
    auto it = s.begin(); // it表示s的第一个字符
    *it = toupper(*it);  // 将当前字符改成大写形式
}
```

+ 将迭代器从一个元素移动到另外一个元素

```cpp
//依次处理s的字符直至我们处理完全部字符或者遇到空白
for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    *it = toupper(*it);//将当前字符改成大写形式
```

+ **关键概念：泛型编程**
+ 迭代器类型
  + 拥有迭代器的标准库类型使用iterator和const_iterator来表示迭代器的类型。
+ **术语：**迭代器和迭代器类型
+ begin和end运算符
  + const_iterator对应的是cbegin和cend。
+ 结合解引用和成员访问操作
  + 简头运算符`->`把解引用和在异口同声访问两个操作结合在一起，也就是`it->mem`和`(*it).mem`表达的意思相同。
+ 某些对vector对象的操作会使迭代器失效

#### 3.4.2、迭代器运算

+ 0
  + **表3.7：vector和string迭代器支持的运算**。
+ 迭代器的算术运算
+ 使用迭代器运算
  + 二分搜索代码.cpp

```cpp
// text必须是有序的
// beg和end表示我们搜索的范围
auto beg = text.begin(),end = text.end();
auto mid = text.begin() + (end - beg)/2; //初始状态下的中间点
//当还有元素尚未检查并且我们还没有找到sought时执行循环
while(mid != end && *mid != sought){
    if(sought < *mid)
        end = mid;
    else
        beg = mid + 1;
    mid = beg + (end - beg)/2; //新的中间点
}
```



### 3.5、数组

#### 3.5.1、定义和初始化内置数组

#### 3.5.2、访问数组元素

#### 3.5.3、指针和数组

#### 3.5.4、C风格字符串

#### 3.5.5、与旧代码的接口

### 3.6、多维数组

## ReadMe

