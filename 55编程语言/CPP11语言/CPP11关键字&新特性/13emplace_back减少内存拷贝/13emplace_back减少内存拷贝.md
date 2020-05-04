## 13emplace_back减少内存拷贝

### 课前秀

+ 与`push_back()`比，**`emplace_back()`能就地通过参数构造对象，不需要拷贝或者移动内存**。
+ 在cppreference.com里搜索“emplace_back”，其实是容器里的一个方法而已。
  + list，deque，vector，pmr::list，pmr::deque，pmr::vector
  + emplace，emplace_hint，emplace_front，emplace_after和emplace_back
+ emplace的意思是**安置就位**，push的意思是推开。

### 1、vector的emplace_back的基本用法

```c++
#include<vector>
#include<iostream>
using namespace std;
struct A
{
    int x;
    double y;
    A(int a, double b):x(a),y(b){}
};

int main()
{
    vector<A> v;
    v.emplace_back(1,2);//通过构造函数的参数构造对象
    cout<<v.size()<<endl;
    return 0;
}
```

### 2、emplace_back和push_back的性能差异

+ [代码2-5所示]，没写呢

## ReadMe

+ 20200504第1版，看《深入应用C++11》2.4。
  + 粗略的知道对push_back省去移动内存，但具体原理是啥，没细追究呢。