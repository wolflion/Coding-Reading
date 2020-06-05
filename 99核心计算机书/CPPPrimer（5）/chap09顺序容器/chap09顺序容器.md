## chap09、顺序容器  291（317/864）

+ 一个**容器**就是一些特定类型对象的集合。**顺序容器（sequential container）的顺序不依赖于元素的值，而是与元素加入容器时的位置相对应**。

### 9.1、顺序容器概述

+ 所有顺序容器都提供了快速顺序访问元素的能力。但以下方面都有不同的性能折中：
  + 向容器添加或从容器中删除元素的代价
  + 非顺序访问容器中元素的代价
+ 顺序容器类型
  + vector
  + deque
  + list
  + forward_list
  + array
  + string
+ 确定使用哪种顺序容器
  + 除非你有很好的理由选择其他容器，否则应使用vector。
  + 如果程序要求随机访问元素，应使用vector或deque。

### 9.2、容器库概览

+ 0
  + 本节，将介绍对所有容器都适用的操作。
  + 一般来说，每个容器都定义在一个头文件中，文件名与类型名相同。**容器均定义为模板类**。
  + `list<Sales_data> // 保存Sales_data对象的list`
+ 对容器可以保存的元素类型的限制
  + `vector<vector<string>> lines;//vector的vector`
  + **某些类没有默认构造函数，但在构造这种容器时不能只传递给它一个元素数目参数：**`vector<noDefault> v2(10);//错误：必须提供一个元素初始化器  `，比如这样`vector<noDefault> v1(10, init);`
  + **表9.2：容器操作**，295（321/864）

#### 9.2.1、迭代器

+ 0
  + 迭代器有着公共的接口：

+ 迭代器范围
  + **左闭合区间**  `[begin,end)`  **范围自begin开始，于end之前结束**。**即不包含end**。
+ 对构成范围的迭代器的要求
+ 使用左闭合范围蕴含的编程假定

```c++
while(begin != end){
    *begin = val; //正确：范围非空，因此begin指向一个元素
    ++begin; //移动迭代器，获取下一个元素
}
```

#### 9.2.2、容器类型成员

+ 每个容器都定义了多个类型。我们已经使用过其中三种：`size_type、iterator、const_iterator`。

```c++
//iter是通过list<string>定义的一个迭代器类型
list<string>::iterator iter;
//count是通过vector<int>定义的一个difference_type类型
vector<int>::difference_type count;
```

#### 9.2.3、begin和end成员

+ 当我们对一个非常对象调用这些成员时，得到的是返回iterator的版本。
+ 只有在对一个const对象调用这些函数时，才会得到一个const版本。
+ **当不需要写访问时，应使用cbegin和cend**。以c开头的版本是const_iterator的。



#### 9.2.4、容器定义和初始化

+ 0
  + 每个容器类型都定义了一个默认构造函数。除array之外。
  + 表9.3：容器定义和初始化  299（325/864）
+ 将一个容器初始化为另一个容器的拷贝
  + （1）可以直接拷贝整个容器
  + （2）array除外，拷贝由一个迭代器对指定的元素范围
  + `deque<string> authList(authors.begin(),it);//拷贝元素，直到（但不包括）it指向的元素`

```c++
//每个容器有三个元素，用给定的初始化器进行初始化
list<string> authors = {"Milton","Shakespeare","Austen"};
vector<const char*> articles = {"a","an","the"};

list<string> list2(authors);//正确：类型匹配
deque<string> authList(authors);//错误：容器类型不匹配
vector<string> words(articles); //错误：容器类型必须匹配

//正确：可以将const char*元素转换为string
forward_list<string> words(articles.begin(), articles.end());
```

+ 列表初始化
  + `vector<const char*> articles = {"a","an","the"};`
+ 与顺序容器大小相同的构造函数

```c++
vector<int> ivec(10,-1);//10个int元素，每个都初始化为-1
list<string> svec(10,"hi!");//10个strings；每个都初始化为“hi!”
forward_list<int> ivec(10);//10个元素，每个都初始化为0
deque<string> svec(10);//10个元素，每个都是空string
```

+ 标准库array具有固定大小

#### 9.2.5、赋值和swap

+ 0
  + **表9.4：容器赋值运算**  302（328/864）
+ 使用assgin（仅顺序容器）

```c++
list<string>names;
vector<const char*> oldstyle;
names = oldstyle;  //错误：容器类型不匹配
//正确：可以将const char*转换为string
names.assign(oldstyle.cbegin(),oldstyle.cend());

//等价于slist1.clear();
//后跟slist1.insert(slist1.begin(),10,"Hiya!");
list<string> slist1(1);//1个元素，为空string
slist1.assign(10,"Hiya!");//10个元素，每个都是"Hiya!"
```



+ 使用swap

#### 9.2.6、容器大小操作

+ 0
  + size()返回容器中元素的数目
  + empty当size为0时返回布尔值true，否则返回false
  + max_size返回一个大于或等于该类型容器所能容纳的最大元素数的值

#### 9.2.7、关系运算符

### 9.3、顺序容器操作

#### 9.3.1、向顺序容器添加元素

#### 9.3.2、访问元素

#### 9.3.3、删除元素

#### 9.3.4、特殊的forward_list

#### 9.3.5、改变容器大小

#### 9.3.6、容器操作可能使迭代器

### 9.4、vector对象是如何增长的

### 9.5、额外的string操作

#### 9.5.1、构造string的其他方

#### 9.5.2、改变string的其他方

#### 9.5.3、string搜索操作

#### 9.5.4、compare函数

#### 9.5.5、数值转换

### 9.6、容器适配器

### 小结  332（358/864）