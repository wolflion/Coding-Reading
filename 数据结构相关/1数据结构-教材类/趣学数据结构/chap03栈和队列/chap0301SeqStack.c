//动态分配的结构体
typedef struct SqStack
{
	int *base;  //栈底
	int *top;  //栈顶
}SqStack;

#define Maxsize 100
/*静态分配的结构体
typedef struct SqStack
{
int data[Maxsize]; //定长数组
int top;   //栈顶下标
}SqStack;
*/

//顺序栈的初始化
bool InitStack(SqStack &S)
{
	S.base = new int[Maxsize];//为顺序栈分配一个最大容量为MaxSize的空间
	if (S.base)
	{
		return false;//分配失败
	}
	S.top = S.base;//top初始化为基地址base，当前为空栈
	return true;
}

//入栈
bool Push(SqStack &S, int e)
{
	//栈满
	if (S.top-S.base == Maxsize)
	{
		return false;
	}
	//*S.top++ = e;
	*S.top = e; //新元素压入栈顶
	S.top++;  //栈顶指针加1
	return true;
}

//出栈
bool Pop(SqStack &S, int &e)//删除S的栈顶元素，暂存在变量e中
{
	//空栈
	if (S.top==S.base)
	{
		return false;
	}
	//e = *--S.top
	e = *S.top;
	S.top--;
	return true;
}

//取栈顶元素
int GetTop(SqStack S)
{
	//栈非空
	if (S.top !=S.base)
	{
		return *(S.top - 1);//减1的原因：top指向了栈顶元素的下一个位置
	}
}

