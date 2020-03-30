//二叉树的结构数组表示法

#include <stdio.h>
#include <stdlib.h>

//树的结构声明（数据、左子树、右子树）
struct tree
{
	int data;
	int left;
	int right;
};

typedef struct tree treenode; //树的结构新类型
treenode btree[15];       //声明树的结构数组


void createbtree(int *data, int len)
{
	int level; //树的层数
	int pos;  //-1是左树，1是右树
	int i;

	btree[0].data = data[0];  //创建树根结点
	for (i = 1; i < len;i++)
	{
		btree[i].data = data[i];  //创建结点内容
		level = 0;//从树根开始
		pos = 0;
		while (pos == 0) //用循环找结点位置
		{
			//比较是左或右子树
			if (data[i] > btree[level].data)
			{
				//右树是否有下一层数
				if (btree[level].right != -1)
				{
					level = btree[level].right;
				}
				else
				{
					pos = -1;//右树
				}
			}
			else
			{
				//左树是否有下一层数
				if (btree[level].left != -1)
				{
					level = btree[level].left;
				}
				else
				{
					pos = -1;//左树
				}
			}
		}
		if (pos == 1)  //创建结点左右位置
		{
			btree[level].left = i;  //连接左子树
		}
		else
		{
			btree[level].right = i; // 连接右子树
		}
	}
}

int main()
{
	int data[10] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
	int i;

	//清除树状结构数组
	for (i = 0; i < 15;i++)
	{
		btree[i].data = 0;
		btree[i].left = -1;
		btree[i].right = -1;
	}

	createbtree(data, 9);//创建二叉树

	printf("   左 数据  右\n");
	printf("------------------\n");
	//输出二叉树内容
	for (i = 0; i < 15; i++)
	{
		//是否是树的结点
		if (btree[i].data != 0)
		{
			printf("%2d:[%2d] [%2d] [%2d]\n", i, btree[i].left, btree[i].data, btree[i].right);
		}
	}
}