#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1024
#define INFINITY 65535
typedef struct
{
	int data[MAXSIZE];  // 在结构中定义一个数组
	int top;            // 指示栈顶元素，在数组中相当于索引
}SeqStack;

void InitStack(SeqStack* stack)
{
	stack->top = -1;
}

int IsEmpty(SeqStack* stack)
{
	if (stack->top == -1)
		return 1;
	return 0;
}

int SeqStack_Top(SeqStack* stack)
{
	if (!IsEmpty(stack))
		return stack->data[stack->top];
	return INFINITY;
}

int SeqStack_Pop(SeqStack* stack)
{
	if (!IsEmpty(stack))
		return stack->data[stack->top--];
	return INFINITY;
}

void SeqStack_Push(SeqStack* stack, int val)
{
	if (stack->top >= MAXSIZE - 1)  // stack full
		return;
	stack->top++;
	stack->data[stack->top] = val;
}

int main()
{
	srand((unsigned)time(0));
	SeqStack stack;
	InitStack(&stack);

	for (int i = 0; i < 50; i++)
	{
		SeqStack_Push(&stack, rand() % 1000);
	}

	printf("栈顶元素：%d\n", SeqStack_Top(&stack));

	printf("栈中元素：");
	for (int i = 0; i < 50; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		printf("%d ", SeqStack_Pop(&stack));
	}
	printf("\n");

	return 0;
}