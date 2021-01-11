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

	printf("栈顶元素: %d\n",*((int*)getTop(lstack)));


	while (lstack->size > 0)
	{
		printf("%d ",*((int*)Pop(lstack)));
	}
	printf("\n");

	Destory(lstack);

	return 0;
}
