// 程序清单9.4 bit.h的实现文件
// bit.c：用于无符号整型数的位运算符

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "bit.h"

unsigned fputb(unsigned n, FILE *f)
{
	int i;
	size_t nb = nbits(n);

	// 打印二进制形式的数
	for (i = 0; i < nb;++i)
	{
		fprintf(f, "%d", test(n, nb - 1 - i));
	}
	return n;
}

unsigned fgetb(FILE *f)
{
	unsigned n = 0;
	size_t nb = nbits(n);
	size_t slen;
	char *buf = malloc(nb + 1);
	char format[9];
	int i;

	if (buf == NULL)
	{
		return 0;
	}

	// 构造读格式（例如："%16[01])"
	sprintf(format, " %%d[01]", nb);
	if (fscanf(f,format,buf) != 1)
	{
		return 0;
	}
	// 在n中设置相应的位
	slen = strlen(buf);
	for (i = 0; i < slen; i++)
	{
		if (buf[slen-1-i] == '1')
		{
			n = set(n, i);
		}
	}

	free(buf);
	return n;
}

unsigned count(unsigned n)
{
	unsigned sum = 0;
	while (n)
	{
		if (n&lu)
			++sum;
		n >>= 1;
	}
	return sum;
}