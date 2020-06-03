## chap10、泛型算法  335（361/864）

+ generic algorithm

### 10.1、概述

+ 0
  + 通常情况下，**算法遍历范围，对其中每个元素进行一些处理**。
  + find算法操作的是迭代器，所以与容器无关。
+ 算法如何工作（以find为例）
+ 迭代器令算法不依赖于容器，......
+ ......，但算法依赖于元素类型的操作
  + 大多数算法提供了一种方法，允许我们使用自定义的操作来代替默认的运算符。
+ **关键概念：**算法永远不会执行容器的操作

### 10.2、初识泛型算法

#### 10.2.1、只读算法

+ 0
  + `find()`，`count()`，`accumulate()`
+ 算法和元素类型
  + 对于`accumulate()`要注意元素加的类型与最后一个参数的类型是否一样。
  + **最好使用cbegin()和cend()**，`string sum = accumulate(v.cbegin(), v.cend(), string(""));`
+ 操作两个序列的算法
  + **equal()**，这里是有前提和假设的。`equal(roster1.cbegin(), roster1.end(), roster2.cbegin());//roster2中的元素数目应该至少与roster1一样多`

#### 10.2.2、写容器元素的算法

+ 0
  + `fill(vec.begin(), vec.end(), 0); //将每个元素重置为0`
+ **关键概念：**迭代器参数
+ 算法不检查写操作
+ 介绍back_inserter
+ 拷贝算法

#### 10.2.3、重排容器元素的算法

+ 0
  + sort
+ 消除重复单词
+ 使用unique
+ 使用容器操作删除元素

### 10.3、定制操作

#### 10.3.1、向算法传递函数

+ 0
+ 谓词（predicate）
  + **谓词**：是一个可调用的表达式，其返回结果是一个能用作条件的值。
  + 一元谓词
  + 二元谓词
+ 排序算法

#### 10.3.2、lambda表达式

+ 0
+ 介绍lambda
  + 可调用对象：函数和函数指针；重载了函数调用运算符的类，lambda表达式。
+ 向lambda传递参数
+ 使用捕获列表
+ 调用find_if
+ for_each算法
+ 完整的biggies

```c++
void biggies(vector<string> &words,vector<string>::size_type sz)
{
    elimDups(words);//将words按字典序排序，删除重复单词
    //按长度排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
    
    //获取一个迭代器，指向第一个满足size()>=sz的元素
    auto wc = find_if(words.begin(), words.end(),[sz](const string &a) {return a.size() >= sz;});
    
    //计算满足size >= sz的元素的数目
    auto count = words.end() - wc;
    cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;
    
    //打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc,words.end(),[](const string &s){cout << s << " ";});
    cout<<endl;
}
```

#### 10.3.3、lambda捕获和返回

+ 0
+ 值捕获
+ 引用捕获
+ **建议：**尽量保持lambda的变量捕获简单化
+ 隐式捕获
+ 可变lambda
+ 指定lambda返回类型

#### 10.3.4、参数绑定

+ 0
+ 标准库bind函数
  + **可以将bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表**。`auto newCallable = bind(callable, arg_list);`
+ 绑定check_size的sz参数
+ 使用placeholders名字
+ bind的参数
+ 用bind重排参数顺序
+ 绑定引用参数
+ 向后兼容：参数绑定

### 10.4、再探迭代器

+ 标准库在头文件`iterator`定义了额外几种迭代器
  + 插入迭代器（insert iterator）：迭代器被绑定到一个容器上，可用来向容器插入元素。
  + 流迭代器
  + 反向迭代器
  + 移动迭代器

#### 10.4.1、插入迭代器

#### 10.4.2、iostream迭代器

+ 0
+ istream_iterator操作
+ 使用算法操作流迭代器

```c++
istream_iterator<int> in(cin),eof;
cout << accumulate(in,eof,0)<<endl;
//输入是 23 109 45 89 6 34 12 90 34 23 56 23 8 89 23
//输出是 664
```

+ istream_iterator允许使用懒惰求值
+ ostream_iterator操作
+ 使用流迭代器处理类类型

#### 10.4.3、反向迭代器

+ 0
+ 反向迭代器需要递减运算符
+ 反向迭代器和其他迭代器间的关系

### 10.5、泛型算法结构

+ 任何算法的最基本的特性是它要求其迭代器提供哪些操作。算法所要求的迭代器操作可以分为5个**迭代器类别（iterator category）**。

#### 10.5.1、5类迭代器

+ 0
+ 输入迭代器
+ 输出迭代器
+ 前向迭代器
+ 双向迭代器
+ 随机访问迭代器

#### 10.5.2、算法形参模式

+ 0
  + 4种
+ 接受单个目标迭代器的算法
+ 接受第二个输入序列的算法

#### 10.5.3、算法命名规范

+ 0
+ 一些算法使用重载形式传递一个谓词
+ _if版本的算法
+ 区分拷贝元素的版本和不拷贝的版本

### 10.6、特定容器算法

+ 0
+ 链表特有的操作会改变容器
  + 链表特有版本与通用版本间一个至关重要的区别是**链表版本会改变底层的容器**。

## ReadMe

+ 20200603看了第1版，确实是有知识脉络的。
  + （1）算法操作的都是**迭代器区间**，跟读、写、重排相关再进行分类。
  + （2）向算法传递**调用函数**，**谓词**满足不了需求，引入lambda表达式，着重把**bind()**介绍了下，*虽然这部分我没好好呢？，不知道是不是跟C++11的std::bind()*
  + （3）进一步讨论**迭代器**相关知识。
  + （4）总结一下**算法的结构（形参模式、命名规范）**。
  + （5）凡事皆有例外，特定容器的算法。