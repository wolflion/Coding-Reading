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

void init(PSTACK);//PSTACK 等价于 struct STACK *
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);

int main()
{

	//栈空：top==bottom;
	//栈满：没有栈满的情况

	STACK s;//等价于struct Stack s;
	int val;
	
	//initStack();//初始化Stack
	//pushStack();//放元素，压栈
	init(&s);
	push(&s,1);//不需要指定位置，只能放在栈顶的位置
	push(&s,2);

	if (pop(&S, &val))//出栈的元素保存到val里 【需要返回值，判断是否成功】
	{
		printf("出栈元素是%d\n", val);
	}

	traverse(&s); //遍历输出

	return 0;
}

void init(PSTACK pS)
{
	//初始化的目的是啥？想达到什么效果？
	//pTop和pBottom 都顶向 无用的头结点，这样一个无用的空栈就造出来了
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		//这部分给指针域 置空
		pS->pTop->pNext = NULL;
		//等价于
		//pS->pBottom->pNext = NULL;
	}
}

void push(PSTACK pS, int value)
{
	//第一步：造出来一个结点
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	//第二步：设置数据域的值，指针域的值。
	pNew->data = val;
	pNew->pNext = pS->pTop; //这里不能改成pS->pBottom;
	//第三步：pTop指向新的栈顶
	pS->pTop = pNew;
}

void traverse(PSTACK pS)
{
	//遍历时，后进新出
	//定义临时参数p，把pTop赋值给p；只要p不是pBttom，就一直输出

	PNODE p = pS->pTop;
	while (p != pS->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	
	return;
}

bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
	{
		return true;
	}
	return false;
}


//把pS所指向的栈，出栈一次，并把出栈的元素存入pVal形参所指向的变量中，如果出栈失败，则返回false，否则返回true
bool pop(PSTACK pS, int *pVal)
{
	//栈为空，则出栈失败
	if (empty(pS))  //pS本身存放的就是S的地址
	{
		return false;
	}
	else
	{
		//pVal = pS->pTop;
		PNODE r = pS->pTop;
		*pVal = r->data;

		pS->pTop = r->pNext;
		free(r);
		r = NULL;

		return true;
	}
}

//clear()只是删除元素（数据）
void clear(PSTACK pS)  //clear(),init(),destroy()
{
	//定义一个p，取得pTop，只要不是pBottom，就要下移，直接free会有问题
	//再定义一个q，指向p的下一个元素

	if (empty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;// p->pNext;

		while (p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
}