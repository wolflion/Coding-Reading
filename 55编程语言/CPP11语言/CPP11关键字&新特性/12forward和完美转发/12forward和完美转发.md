## forward和完美转发

### 0、课前秀

+ [std::forward]( https://zh.cppreference.com/w/cpp/utility/forward )也是头文件中的`<utility>`
+ 右值引用类型是独立于值的。
+ **一个右值引用参数作为函数的形参，在函数内部再转发该参数的时候它已经变成一个左值了，并不是它原来的类型了**。

### 1、完美转发

+ **完美转发**（Perfect Forwarding）：我们需要一种方法能按参数原来的类型转发到另一个函数。
+ **是指在函数模板中，完全依照模板的参数的类型（保持参数的左值、右值特征），将参数传递给函数模板中调用的另外一个函数**。
+ 参数转发的示例

```cpp
template<typename T>
void PrintT(T& t)
{
    cout<<"lvaue"<<endl;
}

template<typename T>
void PrintT(T&& t)
{
    cout<<"rvaue"<<endl;
}

template<typename T>
void TestForward(T&& v)
{
    PrintT(v);
    PrintT(std::forward<T>(v));
    PrintT(std::move(v));
}

Test()
{
    TestForward(1);
    int x = 1;
    TestForward(x);
    TestForward(std::forward<int>(x));
}
```

## ReadMe

+ 20200428看了第1版，《深入应用C++11》2.3，*还是不太懂具体的应用场景在哪，虽然描述部分差不多看懂8成了*