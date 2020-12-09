## 内容

### 1、sizeof介绍

+ 1、[sizeof operator](https://en.cppreference.com/w/cpp/language/sizeof)
+ 2、Queries size of the object or type。 **后面的括号可加，可不加**。

### 2、基本类型（内置类型）的sizeof

+ **注意题干中的32位还是64位字样**。

### 3、类类型的sizeof

## 参考：

1、[关于sizeof的笔试面试题详解](https://www.cnblogs.com/longson/articles/6341464.html)

2、[C/C++中sizeof()的用法——32位和64位下的sizeof（）](https://blog.csdn.net/xunfeng13/article/details/51011509)

## 扩展：

1、sizeof的实现

## 代码：

```cpp
#include <iostream>
using namespace std;

struct sA
{
	char cA;
	int iA;
	double dA;
};


int main()
{
	cout << sizeof(int) << endl;   // 4
	cout << sizeof(unsigned short) << endl;  // 2
	cout << sizeof(double) << endl;  // 8
	cout << sizeof(sA) << endl;  //16
}
```

