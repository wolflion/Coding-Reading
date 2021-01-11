/*
* �������㣺
* 1��namespace�����⣺���ͬ��û���޶����Ļ�����ȫ�ֵ��Ǹ���ǰ�����using��Ҳ�ᱨ��ֻ����coutʱ�޶�namespace��
* 2��3/2/1���ʽ��ֵ�����⣺������������İ�
* 3��map�����⣺map��insert()�󣬵���������ǲ���Ҫ����int����������ʵ���ŵġ�
* 4��stringתchar*��string�ٽ��в�����char*��ֵ�᲻��䣿
* 5��testSize�����⣬64�е�double���⣬�Լ�class�д���static��int���������Ƕ��٣�
* 6��static��Ա�������������������ģ����Լ�����ѡ����ʱ���е�����ʣ��ְٶ�ȷ�����¡� https://www.cnblogs.com/dylanchu/p/11616369.html
* 7��extern �����﷨   https://blog.csdn.net/viafcccy/article/details/88293897   ���������Զ�Σ�����ֻ��һ�Ρ�
*/


#include<iostream>
#include<map>
using namespace std;

extern int externI; //����ȫ�ֱ���
int globalI; //����ȫ�ֱ���
extern int externIvalue = 0; //����ȫ�ֱ�������ֵ
extern void funExtern() {}; //���Ǹ������ˣ�ֻ����extern����ʡ��

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
	//cout << i << end;  //���i��ô�Ͳ���ȷ���أ�
	cout << j << endl;  // ����namespace Aʱ����j���ͱ��벻ͨ����
}

void fun2()
{
	cout << A::i << endl; //2
}

void fun3()
{
	cout << i << endl; //3�����ûд����ȫ�ֵ�
}


template <class T>
inline T max(T& a, T& b)
{
	return a > b ? a : b;
}

// map������
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

// 4��stringתchar*������
void testString2CharArray()
{
	string str = "hello";
	const char* a = str.c_str();  // ���������ü�const�����ӻ����벻����

	cout << str << endl;   // hello
	cout << a << endl;     // hello

	str += string(2, '1');  // ���ʱ��ֻ����'1'�����ĵ��ַ���������"1"�ַ���
	cout << str << endl;  // hello11
	cout << a << endl;    // hello11  ������Ϊ����hello�ء�
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
	cout << sizeof(double) << endl;  // 8  ���ҵ�����64λ�ģ�double����8��
	cout << sizeof(int) << endl;  // 4
	cout << "class size" << endl;
	cout << sizeof(A1) << endl;  //4
	cout << sizeof(B1) << endl;  //4��˵��static�Ŀռ䣬����class�
}

int main()
{
	cout << 3 / 2 / 1 << endl;  // ��������1���Ǵ��������
	cout << endl;
	fun1();
	fun2();
	fun3();

	//testMap();
	testMap();  // ��ô�棬������ô����ġ���ֻ�Ǹ�����˳���йأ��Լ�����ˣ���ΪҪ�Ÿ����ء�

	//testString2CharArray
	testString2CharArray();  // ָ���ַ���ԣ�ֵ���Ǹ�����

	//testSize
	testSize();

	max(10, 5);
	//max(10, 5.2);  // ����Ǳ�������������Ͳ�ƥ��
}