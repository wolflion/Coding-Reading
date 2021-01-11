#include<stdio.h>
#include<stdlib.h>

typedef struct Node* pNode;
typedef struct Stack* LinkStack;
struct Node
{
	int data;
	pNode next; // 指针
};

struct Stack
{
	pNode top; // 栈顶元素指针
	int size;  // 栈大小
};

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

pNode getTop(LinkStack lstack)
{
	if (lstack->size != 0)
		return lstack->top;
	return NULL;
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

int main()
{
	srand((unsigned)time(0));
	LinkStack lstack = NULL;
	lstack = Create();

	int ret;
	ret = IsEmpty(lstack);
	if (ret)
		printf("栈为空!\n");
	else
		printf("栈不为空!\n");

	for (int i = 0; i < 10; i++)
	{
		Push(lstack, rand() % 100);
	}

	ret = IsEmpty(lstack);
	if (ret)
		printf("栈为空!\n");
	else
		printf("栈不为空!\n");

	printf("栈的长度：%d\n", getSize(lstack));

	printf("栈顶元素: %d\n", *((int*)getTop(lstack)));


	while (lstack->size > 0)
	{
		printf("%d ", *((int*)Pop(lstack)));
	}
	printf("\n");

	Destory(lstack);

	return 0;
}
