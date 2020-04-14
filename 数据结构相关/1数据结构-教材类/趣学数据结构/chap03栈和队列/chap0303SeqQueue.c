typedef struct SqQueue
{
	int *base;//空间基地址
	int front, rear;//队头和队尾
}SqQueue;

#define Maxsize 100

//初始化
bool InitQueue(SqQueue &Q)
{
	Q.base = new int[Maxsize];
	if (Q.base)
	{
		return false;//分配失败
	}
	Q.front = Q.rear = 0;//队头和队尾置为0，队列为空
	return true;
}

//入队
bool EnQueue(SqQueue &Q, int e)
{
	if ((Q.rear+1)%Maxsize == Q.front)
	{
		return false;//队满
	}
	Q.base[Q.rear] = e;//新元素插入
	Q.rear = (Q.rear + 1) % Maxsize;//队尾后移一位
}

//出队
bool DeQueue(SqQueue &Q, int &e)
{
	if (Q.rear==Q.front)
	{
		return false;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Maxsize;
	return true;
}