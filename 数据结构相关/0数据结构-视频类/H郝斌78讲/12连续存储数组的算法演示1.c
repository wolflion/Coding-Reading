#include <stdio.h>
#include <malloc.h> //包含了malloc函数
#include <stdlib.h> //包含了exit函数

//定义了一个数组类型，该数据类型的名字叫做 struct Arr，该数据类型含有3个成员
struct Arr
{
	int *pBase; //存储的是数组第一个元素的地址
	int len;    //数组所能容纳的最大元素的个数
	int cnt;    //当前数组有效元素的个数
	//int increment;  //自动增长因子  【当内存不够，长度-扩充1倍】 allocate()函数实现
};

//尾添加时,append()，最好不用add
//插入时，用insert，最好不用add

void init_arr();  //初始化
bool append_arr();//尾追加
bool insert_arr();
bool delete_arr();
int get();
bool is_empty();  //判断数组是否为空
bool is_full();
void sort_arr();
void show_arr();
void inverse_arr(); //逆序输出  倒置

int main()
{
	struct Arr  arr;//struct Arr这是定义类型【数据类型】； arr是定义变量  【全部都是垃圾数字，要初始化】
	//调用init，指向有效地址和有效个数
	printf("%d\n", arr.len);
	init_arr(arr);
	printf("%d\n", arr.len);
	init_arr(&arr);
	printf("%d\n", arr.len);
	return 0;
}

void init_arr(struct Arr array)
{
	array.len = 99; //这个改变，跟实参没有什么关系。
}

void init_arr(struct Arr *pArr)
{
	//*pArr表示指向的arr
	//(*pArr).len = 99;
	//分配内存给它
	pArr->pBase = (int *)malloc(sizeof(int)*length); //因为要考虑分配的大小，这里要传个length参数
	if (pArr->pBase == NULL) // pBase+1指向第2个字节
	{
		printf("动态内存分配失败!\n");
		exit(-1);//终止整个程序
	}
	else
	{
		pArr->len = length;  //总长度是传进来的
		pArr->cnt = 0; //当前的长度是0
	}
	return;
}

bool is_empty(struct Arr *pArr)
{
	if (pArr->cnt == 0)//有效个数为0时，数组为空
	{
		return true;
	}
	else
	{
		return false;
	}
}

//如果传值，效果也是一样的，不过传值的时候，要拷贝 大量字节；传地址只需要传4个。
void show_arr(struct Arr *pArr)
{
	//if数组为空，提示用户数组为空，else 输出数组有效内容
	if (is_empty(pArr))
	{
		//存储不一样，操作一样  【泛型的威力 】
		printf("数组为空!\n");
	}
	else
	{
		for (size_t i = 0; i < pArr->cnt; i++)
		{
			printf("%d ", pArr->pBase[i]);  //pArr是个结构体变量的地址
		}
		printf("\n");
	}
}

//面向对象是间接解决问题

