## 缘起

+ 20201213开始读它，正好有本电子书《C++STL程序员开发指南》chap06的内容。（260/521）。

## 内容

+ vector属于**序列容器**
+ vector是一种**随机访问的数组**类型，提供对数组元素的快速、随机访问、在序列尾部快速、随机地插入和删除操作。
+ vector就是数据结构中的队列、数组和堆栈。

### 6-1、vector编程入门

#### 6-1-1、定义vector

+ 头部第一行添加`#pragma warning(disable:4786)`，可用于消除win下的某类告警

#### 6-1-2、vector初始化

+ 代码中用的是`push_back()`，我的理解这应该不算是初始化，倒是赋值。
+ `reverse()` 作用是： **更改vector的容量**。
+ 勘误：书中用的`reverse()`是错误的，应该是用`resize(4)`，--*至少我这么用后没有报错*。
  + **只是分配后，他的size()值是0，直接用下标操作会报错“vector subscript out of range”**。

#### 6-1-3、vector大小统计

+ `size()`和`capacity()`区别
  + 两个不同函数调整，分别是`resize()`和`reserve()`
+ *作者也没讲出这两者的区别*。

### 6-2、vector基本使用 （265/521）

#### 6-2-1、判断vector是否为空

+ `empty()`
+ 实例6-7:vector判断是否为空实例  *写得有点复杂了*。

#### 6-2-2、使用循环遍历成员

+ `for`循环的例子，上面有写过了。
+ 实例6-8:vector遍历实例，也没啥写的。就写个迭代器相关的吧。

```cpp
vector<char>::iterator MilkshakeIterator;
for(MilkshakeIterator = cVec.begin(); MilkshakeIterator != cVec.end(); ++MilkshakeIterator)
{
    cout<<*MilkshakeIterator<<endl;
}
```

+ *书上的例子说不支持`MilkshakeIterator.begin()+2`的方式来取第3个对象，我但感觉是可以的呢。**哪些容器不支持随机存取呢？**

#### 6-2-3、使用迭代器

+ `for_each()`算法

#### 6-2-4、使用算法



### 6-3、vector高级编程技术（272/521）

#### 6-3-1、vector对象的查找

+ 只是使用了一下`find()`算法。

#### 6-3-2、vector对象的搜索

+ 只是使用了一下`find_if()`算法。

#### 6-3-3、vector字符串处理

#### 6-3-4、vector的排序

#### 6-3-5、vector元素增加

+ `insert()`把对象插入到vector中的任何地方。`push_back()`是把元素加入到vector的后面。

#### 6-3-6、vector元素删除

+ `vector<int>Fred(10,0);//这才是初始化`，或者`vector<int>Bill(Harry.begin(),Harry.end());`
+ `pop_back()删除最后一个元素`
+ `erase()用来删除由一个iterator指出的元素，也可以删除一个范围的元素`
+ **`remove()`不会改变容器的大小，`pop_back()`和`erase()`会改变容器的大小**

#### 6-3-7、vector对象交换

+ `swap()`

### 6-4、vector程序综合实例分析（282/521）

### 代码

```cpp
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
//#pragma warning(disable:4786)  //添加避免告警的语句
using namespace std;

class AVector {
public:
	void init();
	void initValue();
	void getSize();
	void useIterator();
	void useFind();
};

void AVector::init()
{
	// 6-1：vector定义实例
	std::vector<std::string> Myvector;  // 因为前面有写了using语句，可以写成vector<string>模板类，这样。
	cout << __FUNCTION__ << "Myvector" << endl;
}

void AVector::initValue()
{
	// 实例6-4：vector初始化实例
	vector<string> Myvector;
	Myvector.push_back("Chocolate");
	Myvector.push_back("Strawberry");
	Myvector.push_back("Lime");
	Myvector.push_back("Vanilla");
	for (int i = 0; i < 4; i++)
	{
		cout << Myvector[i] << " ";
	}
	cout << endl;

	// 实例6-5：vector初始化实例
	vector<int> iVec;
	cout << __FUNCTION__ << iVec.size() << iVec.capacity() << endl;// 刚定义的时候，2个都是0
	//iVec.reserve(4);
	iVec.resize(4);  // 书中这行写错了，被我注释掉了。会报“vector subscript out of range”
	cout << __FUNCTION__ << iVec.size() << iVec.capacity() << endl;
	for (size_t i = 0; i < 4; i++)  //原书用的是unsigned int，只不过我习惯 size_t代替了
	{
		iVec[i] = i;
		cout << iVec[i]  << " ";
	}
	cout << endl;
}

void AVector::getSize()
{
	typedef vector<int> INTVECTOR;  // 这个要学着点，偷懒才能进步
	INTVECTOR iVec;
	iVec.push_back(42);
	// 1, 1073741823, 1
	cout << __FUNCTION__ << iVec.size() << iVec.max_size() << iVec.capacity() << endl;
	iVec.reserve(1000);
	// 1, 1073741823, 1000
	cout << __FUNCTION__ << iVec.size() << iVec.max_size() << iVec.capacity() << endl;
	iVec.resize(2000);
	// 2000, 1073741823, 1000
	cout << __FUNCTION__ << iVec.size() << iVec.max_size() << iVec.capacity() << endl;
}

void AVector::useIterator()
{

}

void AVector::useFind()
{
	// 实例6-14：通用算法find()使用实例
	vector<string> Fruit;  // 作者用的是vector<char*>的，但push_back("apple")，怎么push_back()不报错的呢？
	vector<string>::iterator FruitIterator;
	Fruit.push_back("Apple");
	Fruit.push_back("Pineapple");
	Fruit.push_back("Star Apple");
	FruitIterator = find(Fruit.begin(), Fruit.end(), "Pineapple");
	if (FruitIterator == Fruit.end())
	{
		cout << "Fruit not found in vector" << endl;
	}
	else
	{
		cout << *FruitIterator << endl;
	}
}

int main()
{
	AVector a;
	a.init();
	a.initValue();
	a.getSize();
	a.useFind();
}
```

## 履历

+ 20201213看了会儿：19:53-21:00。