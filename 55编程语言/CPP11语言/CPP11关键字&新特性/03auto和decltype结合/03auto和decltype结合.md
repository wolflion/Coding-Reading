## auto和decltype的结合

### 0、课前秀

+ `decltype`解决了sum()的类型问题，**但t1和t2并没有声明**，为了解决这个问题，引入了**跟踪返回类型（trailing-return-type）**。

### 1、跟踪返回类型的引入

+ 原先只用decltype的写法

```cpp
template<typename T1, typename T2>
decltype(t1+t2) sum(T1 &t1, T2 &t2)
{
	return t1 + t2;
}
```

+ 现在：auto和decltype的写法

```cpp
template <typename T1, typename T2>
auto sum(T1 &t1, T2 &t2)->decltype( t1 + t2)
{
	return t1 + t2;
}
```

### 2、构成追踪返回类型函数的两个基本元素

+ `auto`占位符
+ 复合符号`->return_type`，即`->decltype(t1+t2)`

### 3、跟踪返回类型函数的实际应用

+ *目前理解不深刻*

## ReadMe

+ 20200421第1版：《深入理解C++11》4.4，《深入应用C++11》写得太简单了。