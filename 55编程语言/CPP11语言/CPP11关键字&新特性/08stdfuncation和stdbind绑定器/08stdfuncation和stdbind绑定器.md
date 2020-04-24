## std::funcation和std::bind绑定器

### 0、课前秀

+ 这次来到了我知识盲区，我也不知道要引入这个，只是在看lambda表达式时看到的关键字，于是再回来看这部分知识。
+ 看功能：**还能方便地实现延迟求值**。*虽然是啥，目前还有点懵*。

### 1、可调用对象（Callable Objects）

+ 1）是一个函数指针
+ 2）是一个具有operator()成员函数的类对象（仿函数）
+ 3）是一个可被转换为函数指针的类对象
+ 4）是一个类成员（函数）指针

### 2、可调用对象包装器--std::function

+ 基本用法

```cpp
#include<iostream>
#include<functional>

void func(void)
{
    std::cout<<__FUNCTION__<<std::endl;
}

class Foo
{
    public:
    static int foo_func(int a)
    {
        std::cout<<__FUNCTION__<<"("<<a<<") ->: ";
        return a;
    }
}
```



## ReadMe

