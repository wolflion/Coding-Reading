#include <stdio.h>

struct Student
{
	int sid;
	int age;
};

struct Student* CreateStudent(void);//要返回动态分配的地址

void ShowStudent(struct Student*);

int main()
{
	struct Student *ps;//指向4个字节
	Struct Student st;//指向8个字节

	ps = CreateStudent();
	ShowStudent(ps);

	return 0;
}

//int型把%s输出的话，会不会导致core？
struct Student* CreateStudent(void)
{
	struct Student *p = (struct Student*)malloc(sizeof(struct Student));
	p->sid = 99;
	p->age = 88;
	return p;
}

void ShowStudent(struct Student* pst)
{
	printf("%d %d\n", pst->sid, pst->age);
}