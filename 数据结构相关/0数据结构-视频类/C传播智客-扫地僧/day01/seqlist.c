#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqlist.h"

//在结构体中套1级指针
typedef struct _tag_SeqList
{
	int length;
	int capcity;
	//int array[capcity];
	unsigned int *node;
}TSeqList;



List* SeqList_Create(int capacity)  //SeqList
{
	int ret = 0;
	TSeqList *tmp = NULL;
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tm == NULL)
	{
		printf("func SeqList_Create() err: %d \n",ret);
		return -1;
	}

	memset(tmp, 0, sizeof(TSeqList);

	//根据capacity的大小分配节点的空间
	tmp->node = (unsigned int *)malloc(sizeof(unsigned int *)*capacity);
	if (tmp->node == NULL)
	{
		ret = -2;
		printf("func SeqList_Create() err: malloc err %d\n", ret);
		return NULL;
	}

	tmp->capcity = capacity;
	tmp->length = 0;

	return NULL;
}

void SeqList_Destroy(List* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TSeqList *)list;
	if (tlist->node != NULL)
	{
		free(tlist->node);
	}
	free(tlist);
	return;
}

//清空链表，就是把长度置0，回到初始化情况
void SeqList_Clear(List* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TSeqList *)list;
	tlist->length = 0;
	return;
}

int SeqList_Length(List *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList *)list;
	return tlist->length;
}

int SeqList_Capacity(List *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList *)list;
	return tlist->capcity;
}