#include<stdio.h>
#include<stdlib.h>
#include "linkstack.h"

int main()
{
	srand((unsigned)time(0));
	LinkStack lstack = NULL;
	lstack = Create();

	int ret;
	ret = IsEmpty(lstack);
	if (ret)
		printf("ջΪ��!\n");
	else
		printf("ջ��Ϊ��!\n");

	for (int i = 0; i < 10; i++)
	{
		Push(lstack, rand() % 100);
	}

	ret = IsEmpty(lstack);
	if (ret)
		printf("ջΪ��!\n");
	else
		printf("ջ��Ϊ��!\n");

	printf("ջ�ĳ��ȣ�%d\n", getSize(lstack));

	printf("ջ��Ԫ��: %d\n",*((int*)getTop(lstack)));


	while (lstack->size > 0)
	{
		printf("%d ",*((int*)Pop(lstack)));
	}
	printf("\n");

	Destory(lstack);

	return 0;
}
