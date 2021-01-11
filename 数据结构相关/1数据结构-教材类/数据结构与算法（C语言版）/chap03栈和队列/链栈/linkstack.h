#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

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

LinkStack Create();
int IsEmpty(LinkStack lstack);
int getSize(LinkStack lstack);
int Push(LinkStack lstack, int val);
pNode getTop(LinkStack lstack);
int Pop(LinkStack lstack);
void Destory(LinkStack lstack);

#endif // !_LINKSTACK_H_
