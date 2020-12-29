## 缘起

## 内容

### 32.1、取消一个线程

+ `int pthread_cancel(pthread_t thread)`
  + Returns 0 on success, or a positive error number on error。

### 32.2、取消状态及类型

+ `int pthread_setcancelstate(int state, int *oldstate);`
+ `int pthread_setcanceltype(int type, int *oldtype);`
  + Returns 0 on success, or a positive error number on error。
+ state的值
  +  PTHREAD_CANCEL_DISABLE
  + PTHREAD_CANCEL_ENABLE
+ type的值
  + PTHREAD_CANCEL_ASYNCHRONOUS
  + PTHREAD_CANCEL_DEFERED

### 32.3、取消点

### 32.4、线程可取消性的检测

+ `void pthread_testcancel(void);`，作用是产生一个取消点。

### 32.5、清理函数（cleanup handler）

+ **在线程终止之前，修改全局变量、解锁互斥量**。挂起状态的收到取消请求后，共享变量或互斥量会置于一种不一致状态。
+ **每个线程都拥有一个清理函数栈**。
+ `void pthread_cleanup_push(void(*routine)(void*),void *arg);`
+ `void pthread_clean_pop(int execute);`

### 32.6、异步取消

+ **用得场景较少**。
+ 异步取消的问题在于，尽管清理函数依然会执行，但处理函数却无从得知线程的具体状态。

### 31.5、总结

### 31.6、练习

## 履历&总结

+ 内容参考《Unix系统编程手册》chap32的框架，20201229看了第1遍，然后总结了个框架，代码啥的也没写，目前还没确定代码的用途。