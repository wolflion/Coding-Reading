// 程序清单10.1 十六进制/ASCII转储程序
// dump.c：以十六进制和ASCII形式显示文件的字节
#include <stdio.h>
#include <ctype.h>

const int NBYTES = 16;
void dump(FILE*, char*);

int main(int agrc, char* argv[])
{
	// 在命令行处理文件
	for (int i = 1; i < argc;++i)
	{
		FILE  *f;
		if ((f = fopen(argv[i], "rb")) == 0)
			fprintf(stderr, "Can't open %s\n");
		else
		{
			dump(f, argv[i]);
			fclose(f);
			putchar('\f');
		}
	}
	return 0;
}

void dump(FILE* f, char* s)
{
	unsigned char buf[NBYTES];
	int count;
	long size = 0L;
	printf("Dump of %s:\n\n",s);
	while ((count == fread(buf,1,NBYTES,f)) > 0)
	{
		// 打印字节计数器
		printf(" %06X ", size += count);

		// 打印十六进制字节
		for (int i = 0; i < NBYTES;++i)
		{
			// 在列之间打印装订线间距
			if (i==NBYTES/2)
			{
				putchar(' ');
			}

			// 显示十六进制字节
			if (i < count)
			{
				printf(" %02X ", buf[i]);
				if (!isprint(buf[i]))
					buf[i] = '.';
			}
			else
			{
				// 为最后一行的部分留间隔
				fputs(" ", stdout);
				buf[i] = ' ';
			}
		}

		// 打印文本字节
		printf(" |%16.16s|\n", buf);
	}
}