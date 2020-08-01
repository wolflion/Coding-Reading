## chap02、保证稳定性和兼容性

### 2.1、保持与C99兼容

#### 2.1.1、预定义宏

+ `_STDC_HOSTED_`
+ `_STDC_`
+ `_STDC_VERSION_`
+ `_STDC_ISO_10646`

#### 2.1.2、`_func_`预定义标识符

#### 2.1.4、变长参数的宏定义以及__VA_ARGS__

+ 变长参数的宏定义:指宏定义中参数列表的最后一个参数为省略号。
+ 预定义宏`__VA_ARGS__`则可以在宏定义的实现部分替换省略号所代表的字符串。`#define PR(...) printf(__VA_ARGS__)`

#### 2.1.5、宽窄字符串的练接

+ 窄字符（char）与宽字符（wchar_t），会自动转换后再与宽字符运算。

### 2.2、long long整型

+ 要了解平台上long long大小的方法就是查看<climits>（或<limits.h>）中的宏。
+ 2-2-1.cpp

### 2.5、静态断言

#### 2.5.1、断言：运行时与预处理时

+ 在通常情况下，**断言**就是将一个返回值总是需要为真的判别式放在语句中，用于排除在设计的逻辑上不应该产生的情况。
+ 用宏`NDEBUG`来禁用assert宏。
+ `#error`预处理指令
	+ ``` #ifndef _COMPLEX_H
              #error "Never use <bits/cmathcalls.h> directly; include <complex.h> instead."
              #endif
          ```

#### 2.5.2、静态断言与static_assert

+ **断言assert宏只有在程序运行时才能起作用。而#error只在编译器预处理时才能起作用**。
+ 2-5-2.cpp

### 2.7、快速初始化成员变量

+ 2-7-1.cpp

### 2.9、扩展的friend语法

+ 2-9-1.cpp
+ 2-9-3.cpp

### 2.10、final/override控制

### 2.11、模板函数的默认模板参数

### 2.12、外部模板

### 2.13、局部和匿名类型作模板实参