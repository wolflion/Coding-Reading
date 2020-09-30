// �����嵥10.1 ʮ������/ASCIIת������
// dump.c����ʮ�����ƺ�ASCII��ʽ��ʾ�ļ����ֽ�
#include <stdio.h>
#include <ctype.h>

const int NBYTES = 16;
void dump(FILE*, char*);

int main(int agrc, char* argv[])
{
	// �������д����ļ�
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
		// ��ӡ�ֽڼ�����
		printf(" %06X ", size += count);

		// ��ӡʮ�������ֽ�
		for (int i = 0; i < NBYTES;++i)
		{
			// ����֮���ӡװ���߼��
			if (i==NBYTES/2)
			{
				putchar(' ');
			}

			// ��ʾʮ�������ֽ�
			if (i < count)
			{
				printf(" %02X ", buf[i]);
				if (!isprint(buf[i]))
					buf[i] = '.';
			}
			else
			{
				// Ϊ���һ�еĲ��������
				fputs(" ", stdout);
				buf[i] = ' ';
			}
		}

		// ��ӡ�ı��ֽ�
		printf(" |%16.16s|\n", buf);
	}
}