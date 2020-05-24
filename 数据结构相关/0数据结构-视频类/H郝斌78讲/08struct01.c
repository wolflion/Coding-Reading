#include <stdio.h>
#include <string.h>

//这只是定义了一个数据类型，【这里没有分配内存】，这里包括3个成员
//类型说是Student不太准确，准确的说法是 struct Student类型。
struct Student
{
	int sid;//学号
	char name[200];
	int age;
};//这个分号不能省

int main(void)
{
	struct Student st = { 1000, "zhangsan", 20 }; //前面是数据类型，所以是个整体。

	//也可以单独赋值 st.age = 22;这样的方式

	st.name = "lisi";//error
	strcpy(st.name, "lisi"); //要通过这样的方式

	printf("%d,%s,%d\n", st.sid, st.name, st.age);//没有提示时，编译一下后再试一下。


	return 0;
}