## 缘起

## 内容

+ 互斥量：帮助线程同步对共享资源的使用
+ 条件变量：允许线程相互通知共享变量的状态发生了变化

### 30.1、保护对共享变量的访问：互斥量

+ **线程的优势**：通过全局变量来共享信息。【代价就是不会同时修改同一变量，所以有了**临界区**的概念】
+ mutex，是（mutual exclusion）的缩写。

#### 30.1.1、静态分配的互斥量

+ `pthread_mutex_t`类型的变量，静态分配就是不用函数，直接`pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;`

#### 30.1.2、加锁和解锁互斥量

+ `int pthread_mutex_lock(pthread_mutex_t *mutex);`
+ `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
  + Returns 0 on success, or a positive error number on error。
+ 有pthread_mutex_trylock()和pthread_mutex_timedlock()

#### 30.1.3、互斥量的性能

#### 30.1.4、互斥量的死锁

#### 30.1.5、动态初始化互斥量

+ `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`
  + Returns 0 on success, or a positive error number on error。
+ `int pthread_mutex_destroy(pthread_mutex_t *mutex);`
  + Returns 0 on success, or a positive error number on error。

#### 30.1.4、互斥量的属性

#### 30.1.4、互斥量类型

### 30.2、通知状态的改变：条件变量（Condition Variable）

#### 30.2.1、由静态分配的条件变量

+ `pthread_cond_t`类型

#### 30.2.2、通知和等待条件变量

#### 30.2.3、测试条件变量的判断条件（predicate）

#### 30.2.4、示例程序：连接任意已终止线程

#### 30.2.5、经由动态分配的条件变量

+ `int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);`
  + Returns 0 on success, or a positive error number on error。

### 30.3、总结

### 30.4、练习

## 履历&总结

+ 内容参考《Unix系统编程手册》chap30的框架，20201229看了第1遍，然后总结了个框架，代码啥的也没写，目前还没确定代码的用途。