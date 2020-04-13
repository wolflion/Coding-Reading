//2019-04-14   0:31
#define MAXQUEUE 10   //队列的最大容量

int queue[MAXQUEUE]; //队列的数组声明
int front = -1;  //队头
int rear = -1; //队尾

//入队
int enqueue(int value)
{
	//队满
	if (rear+1==front||(rear == (MAXQUEUE-1)&&front<=0))
	{
		return -1;
	}
	rear++;
	if (rear==MAXQUEUE)  //是否超过界限
	{
		rear = 0;//从头开始
	}
	queue[rear] = value;
}

//出队
int dequeue()
{
	if (front == rear)  //队空
	{
		return -1;
	}
	front++;
	if (front == MAXQUEUE)  //是否超过界限
	{
		front = 0;//从头开始
	}
	return queue[front];
}

int main()
{
	int input[100];
	int output[100];
	int select;  //选择项1，2，或3
	int i_count = 0;  //数组input的索引
	int o_count = 0;  //数组output的索引
	int loop = 1;//循环控制
	int i, temp;
	while (loop)
	{
		//选项内容
		printf("[1]输入  [2]取出 [3]列出全部内容 ==> ");
		scanf("%d", &select); //导入选项
		switch (select)
		{
			//输入值后将之存入队列
		case 1:
			printf("请输入存入队列的值(%d) ==> ", i_count + 1);
			scanf("%d", &temp);
			if (enqueue(temp) == -1)
			{
				printf("队列全满.\n");
			}
			else
			{
				input[i_count++] = temp;
			}
			break;
			//取出队列的内容
		case 2:
			if ((temp==dequeue()) == -1)
			{
				printf("队列是空的.\n");
			}
			else
			{
				printf("取出队列元素：%d\n", temp);
				output[o_count++] = temp;
			}
			break;
			//退出循环
		case 3:
			loop = 0;
			break;
		}
	}

	printf("输入队列的元素：");
	for (i = 0; i < i_count;i++)
	{
		printf("[%d]", input[i]);
	}

	printf("\n取出队列的元素：");
	for (i = 0; i < o_count; i++)
	{
		printf("[%d]", output[i]);
	}
	printf("\n剩下队列的元素：");
	while ((temp=dequeue())!=-1)
	{
		printf("[%d]", temp);
	}
	printf("\n");
}