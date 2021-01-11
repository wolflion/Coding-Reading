#include<stdio.h>
#include<stdlib.h>
#include "linkstack.h"

LinkStack Create()
{
	LinkStack lstack = (LinkStack)malloc(sizeof(struct Stack));
	if (lstack != NULL)
	{
		lstack->top = NULL;
		lstack->size = 0;
	}
	return lstack;
}

int IsEmpty(LinkStack lstack)
{
	if (lstack->top == NULL || lstack->size == 0)
		return 1;
	return 0;
}

int getSize(LinkStack lstack)
{
	return lstack->size;
}

int Push(LinkStack lstack, int val)
{
	pNode node = (pNode)malloc(sizeof(struct Node));
	if (node != NULL)
	{
		node->data = val;
		node->next = getTop(lstack); // 新元素结点指向下一个结点，链式实现  【先构建一个节点，再放入到link里去，lionel】
		lstack->top = node; // top指向新节点
		lstack->size++;
	}
	return 1;
}

pNode getTop(LinkStack lstack)
{
	if (lstack->size != 0)
		return lstack->top;
	return NULL;
}

int Pop(LinkStack lstack)
{
	if (IsEmpty(lstack))
		return NULL;
	pNode node = lstack->top;
	lstack->top = lstack->top->next;  // top指向下一个元素
	lstack->size--;
	return node;
}

void Destory(LinkStack lstack)
{
	if (!IsEmpty(lstack))
	{
		free(lstack);
		printf("栈已空，不必再销毁!\n");
		return;
	}
	// 栈不为空，需要把栈中的结点都删除释放
	do
	{
		pNode pTmp;
		pTmp = Pop(lstack);
		free(pTmp);
	} while (lstack->size > 0);
	printf("栈销毁成功！\n");
}