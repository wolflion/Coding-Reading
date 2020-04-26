## 06：for循环

### 0、课前秀

+ C++08/98中，不同的容器和数组，遍历的方法不尽相同，写法不统一，也不够简洁。

### 1、for循环的新用法

+ 原先：遍历一个容器的for语句

`for(auto it = arr.begin(); it != arr.end();++it)`

+ 原先：**for_each算法**的用法：

`std::for_each(arr.begin(), arr.end(), do_count);`

+ C++11基于范围的for循环（The range-based for statement）**只读**

`for(auto n : arr)//n是arr中的一个元素；冒号:后面写上需遍历的表达式`

+ **修改容器中的值，需使用引用**

`for(auto &n : arr){n++;}`

+ **只希望遍历，不希望修改，可以定义成`const auto& n`**

### 2、基于范围的for循环的使用细节

+ rang-based for对map的遍历方法

```cpp
for(auto& val : mm) //auto自动推导出的类型是容器中的value_type，而不迭代器
{
    cout<<val.first<<"->"<<val.second<<end;//val的类型是std::pair，需要用val.first和val.second来提取键值
}
```

+ **基于范围的for循环倾向于在循环开始之前确定好迭代的范围，而不是在每次迭代之前都去调用一次arr.end()**。

### 3、让基于范围的for循环支持自定义类型

+ 对于自定义类型来说，分别实现`begin()、end()`方法即可。
+ *迭代器类的实现*--感觉目前还用不到，就先没学。
+ **可以写一个来完善学到的chap01知识**。

##  ReadMe

+ 20200425第1版：参考《深入应用C++11》1.4节。
  + *1.4.3的自定义类型支持没好好学*













