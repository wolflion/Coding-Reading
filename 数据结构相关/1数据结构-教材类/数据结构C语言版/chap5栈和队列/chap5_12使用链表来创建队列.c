//2019-04-12   0:09
#include <stdlib.h>

struct queue_node
{
	int data;
	struct queue_node *next;
};

typedef struct queue_node queue_list;  //定义队列类型
typedef queue_list *link; //定义队列指针类型

link front = NULL;  //队头
link rear = NULL; //队尾

//入队
int enqueue(int value)
{
	link new_node;
	new_node = (link)malloc(sizeof(queue_list));
	if (!new_node)
	{
		printf("内存分配失败！\n");
		return -1;
	}
	new_node->data = value;
	new_node->next = NULL;  //设置初值
	if (rear == NULL)  //是否是第一次存入
	{
		front = new_node;
	}
	else
	{
		rear->next = new_node;  //插入rear之后
	}
	rear = new_node;  //rear指向new_node
}

//出队
int dequeue()
{
	link top;
	int temp;

	if (front != NULL)
	{
		top = front;  //top指向front
		front = front->next;  //删除之前结点
		temp = top->data;//取出数结
		free(top);//释放内存
		return temp;  //队列取出
	}
	else
	{
		return -1;//无法取出
	}
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