## 15type_traits类型萃取

### 0、课前秀

+ trait的意思是**特性，特征**。
+ 搜了一下[<type_traits>](https://zh.cppreference.com/w/cpp/header/type_traits)头文件

### 1、基本的type_traits

#### （1）简单的type_traits

+ C++98/03通过枚举定义**编译期常量**。
+ C++11无须自己定义static const int或enum类型，只需要从std::integral_constant派生。

```c++
template <typename Type>
struct GetLeftSize:std::integral_constant<int,1>
{
    
};
```

+ integral_constant类有一个常量成员函数value，可以通过integral_constant::value来获取interal_constant所代表的真正值。

#### （2）类型判断的type_traits

#### （3）判断两个类型之间的关系traits

+ is_same的用法 
+ is_base_of的用法
+ is_convertible的用法

#### （4）类型的转换traits

+ const的移除和添加
+ 引用的移除和添加
+ 数组的修改
+ 指针的修改

### 2、类型

