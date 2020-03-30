#include <stdio.h>
#include <malloc.h>
#define MaxSize 100

typedef char ElemType;

typedef struct node
{
	ElemType data;   //数据元素
	struct node *lchild; //指向左孩子
	struct node *rchild; //指向右孩子
}BTNode;

//由str串创建二叉链
void CreateBTNode(BTNode* &b, char *str)
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;   //lionel，k为1时是左，k为2时是右；j是str串的循环++变量；top是啥？lionel
	char ch;
	b = NULL;  //建立的二叉树初始时为空
	ch = str[j];

	//str未扫描完时循环
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':  //左结点
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b==NULL)  //p指向二叉树的根结点
			{
				b = p;
			}
			else   //已建立二叉树的根结点
			{
				switch (k)
				{
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}


int main()
{
	BTNode *b, *p, *lp, *rp;
	CreateBTNode(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
}