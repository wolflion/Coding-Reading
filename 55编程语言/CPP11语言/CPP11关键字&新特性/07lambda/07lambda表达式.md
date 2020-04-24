## [lambda表达式]( https://zh.cppreference.com/w/cpp/language/lambda )

### 0、课前秀

+ 应该在其它语言中听过lambda表达式这个词，来自数学概念**λ演算 **，本质是个**匿名函数**。

### 1、lambda表达式的概念和基本用法

+ 语法形式：`[capture] (params) opt -> ret {body;}`
  + capture：捕获列表
  + params：参数
  + opt：函数选项  *这个没懂呢*--lionel
  + ret：返回值类型
  + body：函数体
+ 完整的lambda表达式：`auto f = [](int a) ->int {return a+1;}; `
  + 调用`std::cout<<f(1)<<std::endl;//输出2`
+ 省略的lambda表达式：
  + **省略（或默认）是把双刃剑**。
+ **参数列表为空可省略**：`auto f1 = [](){return 1;};` 等价于`auto f2 = []{return 1;};`
+ 捕获列表的变量：
  + `[]`不捕获任何变量
  + `[&]`捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）
  + `[=]`捕获外部作用域中所有变量，并作为副本在函数体中使用（按值捕获）
  + `[=,&foo]`按值捕获外部作用域中所有变量，并按引用捕获foo变量。
  + `[bar]`按值捕获bar变量，同时不捕获其他变量
  + `[this]`捕获当前类中的this指针，让lambda表达式拥有和当前类成员函数同样的访问权限。**如果已经作用了`&`或者`=`，就默认添加此选项**。捕获this的目的是可以在lambda中使用当前类的成员函数和成员变量。

### 2、声明式的编程风格、简洁的代码

+ 用**仿函数**实现

```cpp
class CountEven
{
    int& count_;
    public:
    CountEven(int& count):count_(count)
    {   
    }
    
    void operator()(int val)
    {
        if(!(val & 1)) //val % 2 == 0
        {
            ++ count_;
        }
    }
};

std::vector<int> v = {1,2,3,4,5,6};
int even_count = 0;
for_each(v.begin(), v.end(), CountEven(even_count));
std::cout << "The number of even is "<<even_count<<std::endl;
```

+ 用lambda替换仿函数（**functor**）

```cpp
std::vector<int> v = {1,2,3,4,5,6};
int even_count = 0;
for_each(v.begin(), v.end(),[&even_count](int val)
         {
             if(!(val & 1))  //val %2 == 0
             {
                 ++ even_count;
             }
         });
```

### 3、在需要的时间和地点实现闭包，使程序更灵活

## ReadMe

+ 20200424第1版：《深入应用C++11》1.6的内容
  + 1.6.3的内容没太看，以为1.5节的知识不重要，缺少这个知识基础了