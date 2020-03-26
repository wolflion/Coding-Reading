//用 +,-,*,/4个运算符，使5 5 5 5 5 = 5

#include "../head.h"

int main()
{
	int j, i[5];//数组i用来保存4个运算符
	int sign;//累加运算时的符号
	int result;  //保存运算式的结果值
	int count = 0;//计数器，统计符合条件的方案
	int num[6];//保存操作数
	float left, right;//保存中间结果
	char oper[5] = { ' ', '+', '-', '*', '-' };
	printf("输入5个数，之间用空格隔开：");
	for ( j = 1; j < 6; j++)
	{
		scanf("%d",&num[j]);
	}
	printf("输入结果：");
	scanf("%d", &result);

	for (i[1] = 1; i[4] <= 4;i[1]++)  //1表+，2表-，3表*，4表/
	{
		if (i[1]<4 ||num[2]!=0) //如果运算是/，则第二个运算数不能为0
		{
			for (i[2] = 1; i[2] <= 4;i[2]++)
			{
				if (i[2] < 4 || num[3] != 0)
				{
					for (i[3] = 1; i[3] <= 4; i[3]++)
					{
						if (i[3] < 4 || num[4] != 0)
						{
							for (i[4] = 1; i[4] <= 4; i[4]++)
							{
								if ((i[4]<4) || (num[5]!=0))
								{
									left = 0;
									right = num[1];
									sign = 1;
									//使用case，将4种运算符填到对应的空格位置，并进行运算
									for (j = 1; j <= 4;j++)
									{
										switch (oper[i[j]])
										{
										case '+':
											left = left + sign*right;
											sign = 1;
											right = num[j + 1];
											break;
										case '-':
											left = left + sign*right;
											sign = -1;  //通过f=-1实现减法
											right = num[j + 1];
											break;
										case '*':
											right = right*num[j + 1]; //实现乘法
											break;
										case '/':
											right = right/num[j + 1]; //实现除法
											break;
										default:
											break;
										}
									}
									//开始判断，如果运算式结果和输入的结果相同，则找到，并输出
									if (left+sign*right == result)
									{
										count++;
										printf("%3d:\n", count);
										for (j = 1; j <= 4;j++)
										{
											printf("%d%c", num[j], oper[i[j]]);
										}
										printf("%d=%d\n", num[5], result);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (count==0)
	{
		printf("没有符合要求的方法！\n");
	}
	//getch();
	return 0;
}