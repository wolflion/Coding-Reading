#include <stdio.h>
#include <string.h>

struct Student
{
	int sid;
	char name[200];
	int age;
};

void f(struct Student *pst); //前置声明

void g(struct Student st);
void g2(struct Student *pst);

int main(void)
{
	struct Student st; //st里面有内存空间   【静态变量，不是malloc分配的】
	int i;//虽然i没有赋值，但给i分配过空间了，里面的值是 垃圾数据

	//通过f()函数来实现修改st里成员的值
	f(&st);

	//printf("%d %s %d\n", st.sid, st.name, st.age);

	//通过函数输出
	g(st);

	g2(&st);

	return 0;
}

//这种方式耗内存，耗时间，不推荐
void g(struct Student st) //传值的话，理论上要占108个字节，结构体相互赋值了
{
	printf("%d %s %d\n", st.sid, st.name, st.age);
}

void g2(struct Student *pst)
{
	printf("%d %s %d\n", pst->sid, pst->name, pst->age);
}

void f(struct Student *pst) //把st的地址，传给了pst
{
	(*pst).age = 10;
	pst->sid = 99;
	strcpy(pst->name, "zhangsan");
}