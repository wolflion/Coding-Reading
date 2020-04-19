#include <stdio.h>

int f(int n)//一第2步：为n分配存储空间
{
	n += 2;
	return n;//二第1步：保存返回结果n   二第2步：释放局部空间和形参  二第3步：找到返回地址
}

int main(void)
{
	int val;
	val = f(5);//一第1步：5发送给被调用函数
	printf("val = %d\n",val);//val值是7  【一第1步：把调用地址也发送给被调用函数】
	return 0;
}