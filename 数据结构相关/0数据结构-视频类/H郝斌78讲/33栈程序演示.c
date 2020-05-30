#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node   //这是元素
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;  //**pTop永远指向顶端元素**
	PNODE pBottom;  //pBottom位置一直不变
}STACK, *PSTACK;

int main()
{

	//栈空：top==bottom;
	//栈满：没有栈满的情况

	STACK s;//等价于struct Stack s;
	
	initStack();//初始化Stack
	pushStack();//放元素，压栈

	return 0;
}