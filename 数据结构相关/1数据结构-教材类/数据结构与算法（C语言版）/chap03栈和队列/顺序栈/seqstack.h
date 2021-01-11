#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#define MAXSIZE 1024
#define INFINITY 65535
typedef struct
{
	int data[MAXSIZE];  // �ڽṹ�ж���һ������
	int top;            // ָʾջ��Ԫ�أ����������൱������
}SeqStack;

void InitStack(SeqStack* stack);
int IsEmpty(SeqStack* stack);
int SeqStack_Top(SeqStack* stack);
int SeqStack_Pop(SeqStack* stack);
void SeqStack_Push(SeqStack* stack, int val);
void SeqStack_Destory(SeqStack* stack);

#endif // !_SEQSTACK_H