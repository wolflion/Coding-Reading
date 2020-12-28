## 缘起

## 内容

### 31.1、线程安全（再论可重入性）

+ **线程不安全**：多个线程并发调用某个函数，共享的全局或静态变量最终值不可知。
+ 实现线程安全的方式：
  + 1、函数与互斥量关联（**影响效率**）
  + 2、共享变量与互斥量关联
+ 哪些是非线程安全函数
+ **可重入函数**：无需使用互斥量即可实现线程安全。**要诀**在于避免对全局和静态变量的使用。

### 31.2、一次性初始化

+ `int pthread_once(pthread_once_t *once_control, void (*init)(void))`
  + Returns 0 on success, or a positive error number on error。

### 31.3、线程特有数据

+ 实现函数线程安全最为有效的方式就是使其可重入。

#### 31.3.1、库函数视角下的线程特有数据

#### 31.3.2、线程特有数据API概述

#### 31.3.3、线程特有数据API详述

+ `int pthread_key_create(pthread_key_t *key, void(*destructor)(void*))`
  + Returns 0 on success, or a positive error number on error。
+ `int pthread_setspecific(pthread_key_t key, const void* value)`
  + Returns 0 on success, or a positive error number on error。
+ `int *pthread_getspecific(pthread_key_t key)`
  + Returns pointer, or NULL if no thread-specific data is associated with key.

#### 31.3.4、使用线程特有数据API

#### 31.3.5、线程特有数据的实现限制

### 31.4、线程局部存储

+ **在全局或静态变量的声明中包含`__thread`说明符即可。例：`static __thread buf[MAX_ERROR_LEN];`

### 31.5、总结

### 31.6、练习

## 履历&总结

+ 内容参考《Unix系统编程手册》chap31的框架，20201228看了第1遍，然后总结了个框架，代码啥的也没写，目前还没确定代码的用途。