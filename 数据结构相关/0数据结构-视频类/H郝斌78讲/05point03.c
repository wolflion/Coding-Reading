#include <stdio.h>

void f(int i)//形参也是局部变量
{
	i = 100;
}

//不是定义了一个名字叫做*i的形参，而是定义了一个形参，该形参名字叫做p，它的类型是int *
void f1(int *i) 
{
	*i = 100;//*i就是main()里的i了，因为他们指向了同一个地方  【相当于在main中写了一句 i = 100;】
}

int main(void)
{
	int i = 9;
	f(i);//两个i不冲突，都是局部变量。
	printf("i = %d\n", i);//i的值还是9

	f1(&i);
	printf("i = %d\n", i);//i的值还是100

	return 0;
}