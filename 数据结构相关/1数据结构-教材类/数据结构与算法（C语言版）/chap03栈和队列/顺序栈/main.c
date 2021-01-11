#include<stdio.h>
#include<stdlib.h>
#include"seqstack.h"

int main()
{
	srand((unsigned)time(0));
	SeqStack stack;
	InitStack(&stack);

	for (int i = 0; i < 50; i++)
	{
		SeqStack_Push(&stack, rand() % 1000);
	}

	printf("ջ��Ԫ�أ�%d\n", SeqStack_Top(&stack));

	printf("ջ��Ԫ�أ�");
	for (int i = 0; i < 50; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		printf("%d ", SeqStack_Pop(&stack));
	}
	printf("\n");

	return 0;
}