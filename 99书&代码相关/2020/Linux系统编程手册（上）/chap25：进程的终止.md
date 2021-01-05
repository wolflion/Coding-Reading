## 缘起

## 内容

### 25.1、进程的终止：_exit()和exit()

+ `void exit(int status);`
+ `void _exit(int status);`
+ exit()比_exit()多做了一些动作：
  + 调用退出处理程序
  + 刷新stdio流缓冲区
  + 执行_exit()系统调用

### 25.2、进程终止的细节

+ 无论进程是否正常终止，都会发生：
  + 关闭所有文件描述符
  + 释放进程的文件锁
  + 分离共享内存段

### 25.3、退出处理程序

#### 注册退出处理程序

+ `int atexit(void (*func)(void));`
  + Return 0 on success
+ `int on_exit(void (*func)(int,void*),void *arg);`
  + Return 0 on success, or nonzero on error

#### 程序范例

### 25.4、fork()、stdio缓冲区以及_exit()之间的交互

#### 例子

+ 标准输出定向到**终端**时，缺省为**行缓冲**。
+ 标准输出定向到**文件**时，缺省为**块缓冲**。

### 25.5、总结

### 25.6、练习

## 履历&总结

+ 内容参考《Unix系统编程手册》chap25的框架，20210105看了第1遍，然后总结了个框架，代码啥的也没写，目前还没确定代码的用途。