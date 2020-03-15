#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef char ElemType;

typedef struct  
{
	ElemType elem[MaxSize];
	int length;
}SqList;

void InitList(SqList *&L)    //用到了 引用的概念，不了解这个知识点时，死活没懂？【不用引用的话，怎么解决呢？】
{
	L = (SqList *)malloc(sizeof(SqList));  //为什么分配的是L?只分配到头结点上？
	L->length = 0;
}

void DestroyList(SqList *L)
{
	free(L);
}

int ListEmpty(SqList *L)  //为何不用bool型？
{
	
	//if (L->length == 0)
		//return true;
	return(L->length == 0);  //这个返回啥呢？
}

int ListLength(SqList *L)
{
	return (L->length);
}

void DispList(SqList *L)
{
	//我没有判空
	if (ListEmpty(L))
		return;

	for (int i = 0; i < L->length; i++)
	{
		printf("%c", L->elem[i]);
	}
	printf("\n");
}

//对这种写法，我有疑问？  为何不 ElemType GetElem(SqList *L, int i)
int GetElem(SqList *L, int i, ElemType &e)
{
	//没有判断是否越界
	if (i<1 || i>L->length)
		return 0;
	e = L->elem[i-1];
	return 1;
}

ElemType GetElemByLionel(SqList *L, int i)  // 是为了用引用，省了些开销？
{
	//这有个副作用：如果越界，怎么判断return的是值，还是越界报错？
	return L->elem[i - 1];
}

//查找元素
int LocateElemByLionel(SqList *L, ElemType e)
{
	if (ListEmpty(L))
		return 0; //返回0，要么L为空，要么没找到e

	for (int i = 0; i < L->length;i++)
	{
		if (e == L->elem[i])
		{
			return i + 1;
		}
		else
		{
			return 0;
		}
	}
}

// 作者的方式
int LocateElem(SqList *L, ElemType e)
{
	int i = 0;
	while (i<L->length && L->elem[i]!=e)
	{
		i++;
	}

	if (i>=L->length)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
}

// 用了引用，这个返回值类型是int，都有点多余啊？【在项目中，返回值int是有意义的，可以用宏名定义】
int ListInsert(SqList *&L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1)  //插入位置不存在
		return 0;
	i--;
	//这个不需要malloc？一下。
	for (j = L->length; j > i;j--) //从后往前拷贝数据，空出一个i的位置
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i] = e;
	L->length++;
	return 1;
}

int ListDelete(SqList* &L, int i, ElemType &e)
{
	int j;
	if (i<1 || i>L->length)
		return 0;

	i--;
	e = L->elem[i];  //这样就能知道，第i个位置的元素值是啥了
	// 前移了一个元素
	for (j = i; j < L->length;j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
	return 1;
}

int main()
{
	SqList *L;
	ElemType e;
	printf("（1）初始化顺序表L\n");
	InitList(L);
	printf("（2）依次采用尾插法插入a,b,c,d,e元素\n");
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("（3）输出顺序表\n");
	DispList(L);
	printf("（4）顺序表L长度=%d\n", ListLength(L));
	printf("（5）顺序表L为%s\n", (ListEmpty(L) ? "空" : "非空"));
	GetElem(L, 3, e);
	printf("（6）顺序表L的第3个元素=%c", e);
	ElemType tmp = GetElemByLionel(L, 3);
	printf("（6）顺序表L的第3个元素=%c", tmp);
	printf("（7）元素a的位置=%d\n", LocateElem(L, 'a'));
	printf("（7）元素a的位置=%d\n", LocateElemByLionel(L, 'a'));
	printf("（8）在第4个元素位置上插入f元素\n");
	ListInsert(L, 4, 'f');
	printf("（9）输出顺序表L:");
	DispList(L);
	printf("（10）删除L的第3个元素\n");
	ListDelete(L, 3, e);
	printf("（11）输出顺序表L:");
	DispList(L);
	printf("（12）释放顺序表L\n");
	DestroyList(L);
}