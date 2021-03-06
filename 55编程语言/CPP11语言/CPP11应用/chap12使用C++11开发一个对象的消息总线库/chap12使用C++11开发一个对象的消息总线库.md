## chap12、使用C++11开发一个对象的消息总线库

### 12.1、消息总线介绍

+ 基于消息总线技术可以有效地解决这些问题，**对象间只通过消息联系，而不是通过直接依赖或者关联**。

### 12.2、消息总线关键技术

+ 消息总线的实现需要解决三个问题：
  + （1）通用的消息定义：让所有的对象都能接受
  + （2）消息的注册：让所有对象都可以注册感兴趣的消息
  + （3）消息分发：

#### 12.2.1、通用的消息定义

#### 12.2.2、消息的注册

+ 1、lambda表达式转换为std::function
  + `1201lambda表达式转换为function的实现.cpp`
+ 2、

#### 12.2.3、消息分发

#### 12.2.4、消息总线的设计思想

### 12.3、完整的消息总线

+ 完整的消息总线需要用到function_traits、NonCopyable和Any，还会用到可变参数模板、右值引用和完美转发等特性。
+ `1203完整的function_traits.cpp`

### 12.4、应用实例

### 12.5、总结