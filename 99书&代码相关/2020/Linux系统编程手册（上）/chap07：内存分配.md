## 缘起

+ 本章的标题是  chap07：内存分配

## 内容

### 0

+ 所谓**通用**：就是指`oepn(),close)(),read(),write()`，不仅对磁盘、管道、终端都一样调用。
+ 文件I/O的**缓冲（buffering）**在chap15章介绍。

### 4.1、概述

+ fileio/copy.c  清单4-1：使用I/O系统调用.c

### 4.2、通用I/O

+ 要实现通用I/O，就必须确保每一文件系统和设备驱动程序都实现了**相同的I/O系统调用集**。
+ `ioctl()`为通用I/O模型之外的专有特性提供了访问接口。

### 4.3、打开一个文件：open()

#### 0

+ `int open(const char *pathname, int flags, .../*mode_t mode*/)`

#### 4.3.1、open()调用中的flags参数

#### 4.3.2、open()函数的错误

#### 4.3.3、creat()系统调用

+ **早期的`open()`不支持创建操作**，所以需要`creat()`系统调用来创建文件。

### 4.4、读取文件内容：read()

+ `ssize_t read(int fd, void *buffer, size_t count);`

### 4.5、数据写入文件：write()

+ `ssize_t write(int fd, void *buffer, size_t count);`

### 4.6、关闭文件：close()

+ `int close(int fd);`
  + 0：success
  + -1：error

+ **要对`close()`的调用进行错误检查**。

### 4.7、改变文件偏移量：lseek()

+ `off_t lseek(int fd, off_t offset, int whence);`
  + -1：error
  + new file offset：success

#### 文件空洞

#### 示例程序seek_io

### 4.8、通用I/O模型以外的操作：ioctl()

+ 用法要见15.5节呢。

### 4.9、总结

### 4.10、练习

## 最后

