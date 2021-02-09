## 缘起

## 内容

### 24.1、fork()、exit()、wait()以及execv()的简介

+ **本节的图要记住**
+ 线程是允许应用程序并发执行多个任务的一种机制。

### 29.2、Pthreads API的详细背景

+ 线程数据类型
+ 线程和errno
  + 多线程程序中，每个线程都有属于自己的errno。
+ Pthreads函数返回值
  + 返回0表示成功，返回正值表示失败。
+ 编译Pthreads程序
  + `-lpthread`
  + 或`cc -pthread`选项

### 29.3、创建线程

+ `int pthread_create(pthread *thread, const pthread_attr_t *attr, void *(*start)(void*),void *arg);`
  + Return 0 on success, or a positive error number on error

### 29.4、终止线程

+ `void pthread_exit(void *retval);`

### 29.5、线程ID

+ `pthread_t pthread_self(void);`
+ `int pthread_equal(pthread_t t1, pthread_t t2);`

### 29.6、连接(joining)已终止的线程

+ `int pthread_join(pthread_t thread, void **retval);`

### 29.7、线程的分离

+ `int pthread_detach(pthread_t thread);`

### 29.8、线程属性

+ `pthread_attr_t`类型参数

### 29.9、线程VS进程

+ 线程的优点：
+ 线程的缺点
  + 要确保线程安全
  + 某个线程的bug，可能会危及该进程的所有线程
  + 每个线程都在争用宿主进程（host process）中有限的虚拟地址空间。

### 29.10、总结

### 29.11、练习

## 履历&总结

+ 内容参考《Unix系统编程手册》chap29的框架，20201230看了第1遍，然后总结了个框架，代码啥的也没写，目前还没确定代码的用途。