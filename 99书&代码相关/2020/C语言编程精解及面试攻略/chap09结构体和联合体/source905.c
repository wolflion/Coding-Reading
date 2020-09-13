// 程序5：使用结构体指针数组来处理一组客户的电子账单信息
// 打印电子账单报表
#include <stdio.h>
#include <conio.h>

// 一个宏，用于显示j个空格
#define SPACE(j)  for(k=1;k<j;k++)\
	fprintf(stdout," ");

// 一个宏，用于显示水平行
#define LINE for(k=1;k<=80;k++)\
	fprintf(stdout, "-");

int main()
{
	struct ebill
	{
		int mno;
		char name[20];
		int previous;
		int present;
		int units;
		float charge;
	};

	struct ebill *p[50];
	int i, j, k, n;
	clrscr();

	// 结构体实例个数
	printf("\nHow many customers? ");
	scanf("%d", &n);

	for (i = 0; i < n;i++)
	{
		// 为结构体动态分配内存
		p[i] = (struct ebill *)malloc(sizeof(struct ebill));

		printf("\nEnter Meter no: ");
		scanf("%d", &p[i]->mno);
		fflush(stdin);

		printf("\nEnter Customer name: ");
		gets(p[i]->name);
		printf("\nEnter Previous reading: ");
		scanf("%d", &p[i]->previous);
		printf("\nEnter Present reading: ");
		scanf("%d", &p[i]->present);
		
		p[i]->units = p[i]->present - p[i]->previous;
		p[i]->charge = p[i]->units*4.50;
	}

	printf("\nPress any key to see report...");
	getch();
	clrscr();

	// 报表头
	SPACE(30);
	fprintf(stdout, "APSEB ELECTRICITY BILLS\n");

	LINE;

	fprintf(stdout, "\n%5s", "SNO");
	fprintf(stdout, "%6s", "METER");
	fprintf(stdout, "%4s", " "); // gap of 4 spaces
	fprintf(stdout, "%-20s", "CUSTOMER NAME");
	fprintf(stdout, "%10s", "PREVIOUS");
	fprintf(stdout, "%10s", "PRESENT");
	fprintf(stdout, "%10s", "UNITS");
	fprintf(stdout, "%15s", "CHARGE");

	LINE;

	// 显示数据
	for (i = 0; i < n; i++)
	{
		fprintf(stdout, "\n%5d", i+1);
		fprintf(stdout, "%6d", p[i]->mno);
		fprintf(stdout, "%4s", " "); 
		fprintf(stdout, "%-20s", p[i]->name);
		fprintf(stdout, "%10s", p[i]->previous);
		fprintf(stdout, "%10s", p[i]->present);
		fprintf(stdout, "%10s", p[i]->units);
		fprintf(stdout, "%15s", p[i]->charge);
	}

	fprintf(stdout, "\n");

	LINE;
}