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

bool is_full(struct Arr *pArr)
{
	if (pArr->cnt == pArr->len)
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

bool append_arr(struct Arr* pArr, int val)
{
	//满时返回false
	if (is_full(pArr))
	{
		return false;
	}

	//不满时追加
#if 0
	pArr->pBase[cnt] = val;
	++cnt;
#endif
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}

// pos是插入的位置，从1开始，写3就是pBase[2]，第3个元素之前插入val
// val是插入的值
bool insert_arr(struct Arr *pArr, int pos, int val)
{
	if (is_full(pArr))
	{
		return false;  //如果数组满了，直接返回false
	}

	//这里应该是有效个数，而不是len
	if (pos < 1 || pos > pArr->cnt+1)  //不满的情况下，再判断pos的值
	{
		return false;
	}

	//先往后移，然后再插入数据
	for (size_t i = pArr->cnt-1; i >pos-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	（pArr->cnt)++;
	return true;
}

//返回 删除值的元素
bool delete_arr(struct Arr *pArr, int pos, int *pVal)
{
	if (is_empty(pArr))
	{
		return false;
	}

	//pos值不合法，返回false
	if (pos < 1 || pos > pArr->cnt)
	{
		return false;
	}

	*pVal = pArr->pBase[pos - 1];
	//从pos开始，一直到cnt
	for (size_t i = pos; i < pArr->cnt; ++i)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;
}

void inverse_arr(struct Arr *pArr)
{
	int i = 0, j = pArr->cnt - 1;
	int t;
	while (i<j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
}

//冒泡排序
void sort_arr(struct Arr *pArr)
{
	//第一轮：用第1个元素与所有元素比一下。【已经找到最小或最大的了】
	//第二轮：用第2直元素与其它元素比一下。
	int i, j;
	for (i = 0; i < pArr->cnt;++i)
	{
		for (j = i+1; j < pArr->cnt;++j)
		{
			if (pArr->pBase[i]>pArr->pBase[j])
			{
				int t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		} 
	}
}

//find_val_arr()
//deleteAll(4)

//可以先拿二级C，来练练手；然后再看数据结构