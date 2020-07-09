## C++基础视频day04：

### 02、const修饰的是谁

+ 指的是类中的const成员函数。`void OpVar(int a, int b) const{}`
+ **const修饰的是this指针**，等价于`void OpVar(const Test *this, int a, int b)`，因为this指针隐藏了，所以就放在前后了，这样C++编译器能够解析。


## ReadMe
+ 20200709整理了02。