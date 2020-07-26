#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、给一个已知类型起个别名
#if 0
struct Person
{
	char name[64];
	int age;
};

typedef struct Person myPerson;
#endif

//等价于
typedef struct Person
{
	char name[64];
	int age;
}myPerson;

void test01()
{
	struct Person p;
	myPerson p1;//两个一样的
}

// 第2种：
char* p1, p2;//p1是char*, p2是char类型     【要改成char *p1, *p2;//这是vs的锅吧，gcc有没有?】
//可以用以下方法输出类型  cout<<typeid(p1).name()<<endl;
// 为了避免这种方式 ，可以用typedef
typedef char* pCHAR;  //这还是要加分号的
pCHAR a，b;

// 第3种：屏蔽平台的细节，便于移植，比如A平台下 long long不支持，可以用typedef
typedef long long LLong;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}