#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

int dotProduct(int x[], int y[], int n)
{
	int i, sum;
	sum = 0;
	for (i = 0; i < n;i++)
	{
		sum += x[i] * y[i];
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int i;
	for ( i = 1; i < argc; i++)
	{
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL)
		{
			fprintf(stderr, "%s: can't open '%s' (%s)\n", argv[0], argv[1], strerror(errno));
			return EXIT_FAILURE;
		}
		else
		{
			doubleword(argv[i], fp);
			fclose(fp);
		}
	}
	if (argc == 1)
	{
		doubleword(NULL, stdin);
	}
	return EXIT_FAILURE;
}