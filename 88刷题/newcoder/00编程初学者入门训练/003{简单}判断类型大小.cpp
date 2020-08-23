/*
题目描述
确定不同整型数据类型在内存中占多大（字节），输出不同整型数据类型在内存中占多大（字节）。 
输入描述:
无
输出描述:
不同整型数据类型在内存中占多大（字节），具体格式详见输出样例，输出样例中的?为不同整型数据类型在内存中占的字节数。输出样例如下：
The size of short is ? bytes.
The size of int is ? bytes.
The size of long is ? bytes.
The size of long long is ? bytes.
*/

#include <stdio.h>
#include <stdlib.h>    // 有种说法，stdlib.h，要和stdio.h搭配使用呢。

int main()
{
	printf("The size of short is %d bytes.\n",sizeof(short));
	printf("The size of int is %d bytes.\n", sizeof(int));
	printf("The size of long is %d bytes.\n", sizeof(long));
	printf("The size of long long  is %d bytes.\n", sizeof(long long ));  //这里的is前面，多了一个空格，有点坑。哈哈。【一直报错说是格式问题】
	return 0;
}

// 人家的例子
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("The size of short is %d bytes.\n",sizeof(short));
    printf("The size of int is %d bytes.\n",sizeof(int));
    printf("The size of long is %d bytes.\n",sizeof(long));
    printf("The size of long long is %d bytes.\n",sizeof(long long));
    return 0;
}