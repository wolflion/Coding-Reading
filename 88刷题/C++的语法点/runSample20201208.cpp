/*
* 几个考点：
* 1、namespace的问题：如果同名没有限定符的话，是全局的那个；前面加了using，也会报错；只有在cout时限定namespace。
* 2、3/2/1表达式求值的问题：从右往左运算的吧
* 3、map的问题：map的insert()后，迭代器输出是不是要根据int进行排序，其实不排的。
* 4、string转char*后，string再进行操作，char*的值会不会变？
* 5、testSize的问题，64中的double问题，以及class中存在static的int变量到底是多少？
* 6、static成员变量，是所有类对象共享的；【自己看到选择题时，有点存疑问，又百度确认了下】 https://www.cnblogs.com/dylanchu/p/11616369.html
* 7、extern 声明语法   https://blog.csdn.net/viafcccy/article/details/88293897   【声明可以多次，定义只能一次】
*/


#include<iostream>
#include<map>
using namespace std;

extern int externI; //声明全局变量
int globalI; //定义全局变量
extern int externIvalue = 0; //定义全局变量并初值
extern void funExtern() {}; //这是个定义了，只不过extern可以省略

int i = 3;
namespace A
{
	int i = 2;
	int j = 0;
};

namespace B
{
	int i = 1;
	void fun1();
	void fun2();
	void fun3();
}

void fun1()
{
	using namespace A;
	//cout << i << end;  //这个i怎么就不明确了呢？
	cout << j << endl;  // 不加namespace A时访问j，就编译不通过。
}

void fun2()
{
	cout << A::i << endl; //2
}

void fun3()
{
	cout << i << endl; //3，这个没写就是全局的
}


template <class T>
inline T max(T& a, T& b)
{
	return a > b ? a : b;
}

// map的问题
void testMap()
{
	map<string, int>dict;
	dict.insert(make_pair("abcdef",3));
	dict.insert(make_pair("abcdefg", 2));
	dict.insert(make_pair("bcdef", 1));

	map<string, int>::iterator it;
	for (it = dict.begin(); it != dict.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}

// 4、string转char*的问题
void testString2CharArray()
{
	string str = "hello";
	const char* a = str.c_str();  // 这个还必须得加const，不加还编译不过。

	cout << str << endl;   // hello
	cout << a << endl;     // hello

	str += string(2, '1');  // 这个时候只能是'1'这样的单字符，不能是"1"字符串
	cout << str << endl;  // hello11
	cout << a << endl;    // hello11  【我以为还是hello呢】
}

class A1
{
private:
	int m_i;
};

class B1
{
private:
	int m_i;
	static int i;
};


void testSize()
{
	cout << sizeof(double) << endl;  // 8  【我电脑是64位的，double就是8】
	cout << sizeof(int) << endl;  // 4
	cout << "class size" << endl;
	cout << sizeof(A1) << endl;  //4
	cout << sizeof(B1) << endl;  //4，说明static的空间，不在class里。
}

int main()
{
	cout << 3 / 2 / 1 << endl;  // 这个结果是1，是从右往左的
	cout << endl;
	fun1();
	fun2();
	fun3();

	//testMap();
	testMap();  // 怎么存，就是怎么输出的。【只是跟存入顺序有关；自己想多了，以为要排个序呢】

	//testString2CharArray
	testString2CharArray();  // 指向地址不对，值还是跟着走

	//testSize
	testSize();

	max(10, 5);
	//max(10, 5.2);  // 这就是编译错误，两个类型不匹配
}