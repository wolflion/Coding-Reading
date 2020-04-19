//不同函数之间的相互调用
#include <stdio.h>

void f();
void g();
void k();

void f()
{
	printf("FFFF\n");
	g();
	printf("1111\n");
}

void g()
{
	printf("GGGG\n");
	k();
	printf("222\n");
}

void k()
{
	printf("KKKK\n");
	//f(); //会出现死递归，**但压栈的次数系统也是有限制的**
}

int main(void)
{
	f();
	return 0;
}

//输出：FGK21，这样的顺序