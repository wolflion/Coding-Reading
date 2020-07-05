#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;

typedef struct node
{
	ElemType data;//数据元素
	struct node* lchild; //指向左孩子
	struct node* rchild; //指向右孩子
}BTNode;

//由str串创建二叉链
void CreateBTNode(BTNode* &b, char *str)
{
	BTNode*St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;//建立的二叉树初始时为空

	ch = str[j];
	while (ch != '\0')  //str未扫描完时循环
	{
		switch (ch)
		{
		//左结点
		case'(':  
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
	    // 右结点
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			//p指向二叉树的根结点
			if (b==NULL)
			{
				b = p;
			}
			//已建立二叉树根结点
			else
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

//返回data域为x的结点指针
BTNode* FindNode(BTNode *b, ElemType x)
{
	BTNode *p;
	if (b==NULL)
	{
		return NULL;
	}
	else if (b->data==x)
	{
		return b;
	}
	else
	{
		p = FindNode(b->lchild, x);
		if (p!=NULL)
		{
			return p;
		}
		else
		{
			return FindNode(b->rchild, x);
		}
	}
}

//返回*p结点的左孩子结点指针
BTNode* LchildNode(BTNode *p)
{
	return p->lchild;
}

//返回*p结点的右孩子结点指针
BTNode* RchildNode(BTNode *p)
{
	return p->rchild;
}

//求二叉树的深度
int BTNodeDepth(BTNode *b)
{
	int lchilddep, rchilddep;
	if (b==NULL)
	{
		return(0);
	}
	else
	{
		lchilddep = BTNodeDepth(b->lchild);  //左子树的高度
		rchilddep = BTNodeDepth(b->rchild);  //右子树的高度
		return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
	}
}

//以括号表示法输出二叉树
void DispBTNode(BTNode *b)
{
	if (b!=NULL)
	{
		printf(" %c ", b->data);
		if (b->lchild !=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispBTNode(b->lchild);
			if (b->rchild !=NULL)
			{
				printf(",");
			}
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}

//求二叉树的宽度
int BTWidth(BTNode *b)
{
	//定义顺序非循环队列
	struct
	{
		int lno;//结点的层次编号
		BTNode *p;//结点指针
	}Qu[MaxSize];

	int front, rear;//队首，队尾指针
	int lnum, max, i, n;
	front = rear = 0;//置队列为空队

	if (b!=NULL)
	{
		rear++;
		//根结点指针入队
		Qu[rear].p = b;
		//根结点的层次编号为1
		Qu[rear].lno = 1;

		//此循环通过层次层次遍历求每个结点的层次
		while (rear != front)
		{
			front++;
			b = Qu[front].p;//队头出队
			lnum = Qu[front].lno;

			//左孩子入队
			if (b->lchild !=NULL)
			{
				rear++;
				Qu[rear].p = b->lchild;
				Qu[rear].lno = lnum + 1;
			}

			//右孩子入队
			if (b->rchild != NULL)
			{
				rear++;
				Qu[rear].p = b->rchild;
				Qu[rear].lno = lnum + 1;
			}
		}

		//lnum从第1层开始
		max = 0;
		lnum = 1;
		i = 1;

		//通过比较相同层次的结点数  求树的宽度
		while (i <= rear)
		{
			n = 0;
			while (i <= rear &&Qu[i].lno == lnum)
			{
				//n累计lnum层中的结点个数
				n++;
				i++;
			}
			//取一个新的结点层次
			lnum = Qu[i].lno;
			//将最大层次结点数赋给max
			if (n>max)
			{
				max = n;
			}
		}
		return max;
	}
	else
	{
		return 0;
	}
}


//求二叉树b的结点个数
int Nodes(BTNode *b)
{
	int num1, num2;
	//树空的情况
	if (b==NULL)
	{
		return 0;
	}
	//叶子结点的情况
	else if (b->lchild == NULL && b->rchild == NULL)
	{
		return 1;
	}
	//其它情况
	else
	{
		num1 = Nodes(b->lchild);
		num2 = Nodes(b->rchild);
		//返回左右子树结点数加1
		return(num1 + num2 + 1);
	}
}

//求二叉树b的叶子结点个数
int LeafNodes(BTNode *b)
{
	int num1, num2;
	//树空的情况
	if (b == NULL)
	{
		return 0;
	}
	//叶子结点的情况
	else if (b->lchild == NULL && b->rchild == NULL)
	{
		return 1;
	}
	//其它情况
	else
	{
		num1 = Nodes(b->lchild);
		num2 = Nodes(b->rchild);
		//返回左右子树结点数
		return(num1 + num2);
	}
}

int main(int argc, char** argv)
{
	BTNode *b, *p, *lp, *rp;
	CreateBTNode(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("(1)输出二叉树: ");
	DispBTNode(b);
	printf("\n");

	printf("(2) 'H'结点：");
	p = FindNode(b, 'H');
	
	if (p!=NULL)
	{
		lp = LchildNode(p);
		if (lp != NULL)
		{
			printf("左孩子为%c", lp->data);
		}
		else
		{
			printf("无左孩子");
		}

		rp = RchildNode(p);
		if (rp != NULL)
		{
			printf("右孩子为%c", rp->data);
		}
		else
		{
			printf("无右孩子");
		}
	}

	printf("\n");
	printf("(3)二叉树b的深度：%d\n", BTNodeDepth(b));
	printf("(4)二叉树b的宽度：%d\n", BTWidth(b));
	printf("(5)二叉树b的结点个数：%d\n", Nodes(b));
	printf("(6)二叉树b的叶子结点个数：%d\n", LeafNodes(b));


	getchar();
	return 0;
}

/*
(1)输出二叉树:  A ( B ( D , E ( H ( J , K ( L , M (, N ))))), C ( F , G (, I )))
(2) 'H'结点：左孩子为J右孩子为K
(3)二叉树b的深度：7
(4)二叉树b的宽度：4
(5)二叉树b的结点个数：14
(6)二叉树b的叶子结点个数：13
*/