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
		node->next = getTop(lstack); // ��Ԫ�ؽ��ָ����һ����㣬��ʽʵ��  ���ȹ���һ���ڵ㣬�ٷ��뵽link��ȥ��lionel��
		lstack->top = node; // topָ���½ڵ�
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
	lstack->top = lstack->top->next;  // topָ����һ��Ԫ��
	lstack->size--;
	return node;
}

void Destory(LinkStack lstack)
{
	if (!IsEmpty(lstack))
	{
		free(lstack);
		printf("ջ�ѿգ�����������!\n");
		return;
	}
	// ջ��Ϊ�գ���Ҫ��ջ�еĽ�㶼ɾ���ͷ�
	do
	{
		pNode pTmp;
		pTmp = Pop(lstack);
		free(pTmp);
	} while (lstack->size > 0);
	printf("ջ���ٳɹ���\n");
}