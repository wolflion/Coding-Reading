## 24、final和override关键字

### 0、课前秀

+ 抛开别的语言不谈，就重新引入两个关键字`final`和`override`
+ final的意思是*最终的*，所以可以理解为最后的子类了。

### 1、final关键字

+ 用于限制某个类不能被继承，或者**某个虚函数不能被重写**，修饰函数，final只能修饰虚函数，并且要放到类或者函数的后面。
+ final的用法

```cpp
struct A
{
    //A::foo is final 限定该虚函数不能被重写
    virtual void foo() final;
    //Error: non-virtual function cannot be final，只能修改虚函数
    void bar() final;
};

struct B final : A  //struct B is final
{
    //Error: foo cannot be overridden as it's final in A
    void foo();
};

struct C : B //Error: B is final
{
    
};
```

### 2、override关键字

+ 确保在派生类中声明的重写函数与基类的虚函数有相同的签名，同时也明确表明将会重写基类的虚函数，还可以防止因疏忽把本来想重写基类的虚函数声明成重载。
+ 保证重写虚函数的正确性，又提高代码的可读性。**关键字要放到方法后面**。
+ 代码示例

```cpp
struct A
{
    virtual void func() {}
};

struct D : A{
    //显式重写
    void func() override
    {
        
    }
};
```

## ReadMe

+ 语法上get到了，但具体的应用场景还是再实践。20200511看完第1版，《深入应用C++11》7.3内容。