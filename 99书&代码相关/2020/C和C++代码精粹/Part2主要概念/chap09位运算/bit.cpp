// �����嵥9.4 bit.h��ʵ���ļ�
// bit.c�������޷�����������λ�����

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "bit.h"

unsigned fputb(unsigned n, FILE *f)
{
	int i;
	size_t nb = nbits(n);

	// ��ӡ��������ʽ����
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

	// �������ʽ�����磺"%16[01])"
	sprintf(format, " %%d[01]", nb);
	if (fscanf(f,format,buf) != 1)
	{
		return 0;
	}
	// ��n��������Ӧ��λ
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