## 缘起

## 内容

### 基础内容

+ **完全理解书上的知识点后，多看看[cplusplus中的string知识点](http://cplusplus.com/reference/string/string/)**。

+ 1、支持`Iterators`，**迭代器的种类**多个。
+ 2、**Capacity**相关，也有好多个，不能只用`size()`
+ 3、**Element access**，用`at(),back(),front()`
+ 4、**Modifies**：除了`append()`之种，还支持`push_back`和`assign()`这些的。
+ 5、**String operations**：除了`c_str(),find(),substr()`，还有`compare()`
+ 6、**Member constants**，里面有`npos()`，这个不太熟悉呢。
+ 7、**Non-member function overloads**。

### 代码

+ 《C++ STL基础及应用》的chap05字符串
+ 代码在win下的vs2019社区版，运行通过。

```cpp
#include<iostream>
#include<string>
#include <sstream>
using namespace std;

class AString {
public:
	AString() :iValue(0), sValue()
	{

	}
	void init();  // 字符串创建及初始化

	void oper();  // 字符串操作

	void query();  // 字符串查询，这个知识点有点多

	void del();   // 字符串删除

	void cmp();   // 字符串比较

	int GetInt(string s);  //把字符串转化为整型

	string GetString(int n);  //把整型转化为字符串

	string GetTrim(string& s);  //去字符串两侧的空格
private:
	int iValue;
	string sValue;
};

void AString::init()    // 还是要用IDE，自己忘记写void了
{
	string s1;   // 被创建，但不包含初始值。【被初始化成“没有字符”】，长度为0，没有数据元素
	string s2("How are you?");
	string s3(s2);
	string s4(s3, 0, 2);  // 偏移量，计数量。【从偏移量0的字符开始，连续取3个字符，构成的字符串】
	string s5="fine";  //把char型数组，赋值给s5。
	string s6 = s2 + s5;  // += 没有被重载？

	// string对象赋值，等号右边第一项必须是string类型。【这条好像不生效了吗？】
	string s7 = "fine" + s2;  // 书上虽然讲这个不行，但VS2019还是可以运行的。
	cout << __FUNCTION__ << s1 << s2 << s3 << s4 << s5 << s6 << s7 << endl;

	// 用迭代器的方式
	string s8(s2.begin(), s2.end());  // 将string当作一个容器
	string s9(s2.begin() + 4, s2.begin() + 7);
	string s10(4, 65);  //输出4个A,A的ascii的值是65。  【这是我自己加的，估计也重载到了】
	cout << s8 << s9 <<s10<< endl;
}


void AString::oper()
{
	// 插入操作  【string的插入操作，无需像char数组一样，申请空间】
	string s1 = "do";
	cout << __FUNCTION__ << "Inition size is :" <<s1.size() << endl;
	s1.insert(0, "How");   // 串首，串尾，或任意处插入，修改第1个参数即可。
	cout << __FUNCTION__ << s1 << endl;
	s1.append("you");  // 尾部追加
	cout << __FUNCTION__ << s1 << endl;
	s1 = s1 + "do?";// 用+
	cout << __FUNCTION__ << s1 << endl;

	// 替换操作 replace()
	string s = "what's your name?";
	cout << __FUNCTION__ << "before value is :" << s << endl;
	s.replace(7, 4, "her");
	cout << __FUNCTION__ << "replace value is :" << s << endl;
}


void AString::query()
{
	// 查询
	string s = "What's your name? my name is TOM. How do you do? Fine, thanks.";
	int n = s.find("your");
	cout << __FUNCTION__ << n << endl;
	n = s.find("you", 15);
	cout << __FUNCTION__ << n << endl;
	n = s.find_first_of("abcde");
	cout << __FUNCTION__ << n << endl;
	n = s.find_first_of("abcde",3);
	cout << __FUNCTION__ << n << endl;
}

void AString::del()
{
	// 删除，用的是erase()方法，还是迭代器，别的方式可以吗？
	string s1 = "How are you?";
	s1.erase(s1.begin(), s1.begin() + 3);
	cout << __FUNCTION__ << s1 << endl;
	s1.erase(s1.begin(), s1.end());
	cout << __FUNCTION__ << s1 << endl;  //因为删光了，就没有显示结果。
}

void AString::cmp()
{
	// 用的还是运算符重载
	string s1 = "this";
	string s2 = "that";
	if (s1 == s2)
		cout << __FUNCTION__ << "s1 == s2" << endl;
	if (s1 > s2)
		cout << __FUNCTION__ << "s1 > s2" << endl;
	if (s1 < s2)
		cout << __FUNCTION__ << "s1 < s2" << endl;
}

int AString::GetInt(string s)
{
	//int n = 0;
	stringstream os;
	os << s;
	os >> iValue;
	return iValue; //明明可以用局部变量的，我非要show一把代码规范，不用局部变量的返回值。
}

string AString::GetString(int n)
{
	stringstream os;
	os << n;
	os >> sValue;
	return sValue;
}

// 原书传的是string s，我改写成引用了
string AString::GetTrim(string& s)
{
	s.erase(0, s.find_first_not_of(" "));//删除左空格
	s.erase(s.find_last_not_of(" ") + 1); // 删除右空格
	return s;
}

int main()
{
	AString a;
	a.init();
	a.oper(); 
	a.query();
	a.del();
	a.cmp();
	cout << a.GetInt("123") << endl;
	cout << a.GetString(456) << endl;
	string s = " hello ";
	cout << a.GetTrim(s) << endl;
}

```

## 履历

+ 20201211整理掉《C++ STL基础及应用》的chap05字符串，19:30-20:26 （书是第1版，我有个电子版）
+ [cplusplus上的string](http://cplusplus.com/reference/string/string/)