// 程序4：使用结构体数组来处理人群的地址标签
// 使用结构体打印地址标签
#include <stdio.h>
#include <conio.h>

// 一个宏，用于显示水平行
#define LINE for(k=1;k<=70;k++)\
	fprintf(stdout, "-");

int main()
{
	struct addlabel
	{
		char name[20];
		char address[30];
		char city[20];
		char pin[10];
	};

	struct addlabel a[50];
	int i, k, n;
	clrscr();

	// 结构体数组的大小
	printf("\nHow many customers? ");
	scanf("%d", &n);

	fflush(stdin);

	for (i = 0; i < n;i++)
	{
		printf("\nEnter customer name: ");
		gets(a[i].name);

		printf("\nEnter address: ");
		gets(a[i].address);
		printf("\nEnter city: ");
		gets(a[i].city);
		printf("\nEnter pincode: ");
		gets(a[i].pin);
	}

	printf("\nPress any key to see report...");
	getch();
	clrscr();

	// display 2 labels at a time
	for (i = 0; i < n; i+=2)
	{
		fprintf(stdout, "\n%-35s", a[i].name);
		if (i + 1 < n)
		{
			fprintf(stdout, "\n%-35s", a[i+1].name);
		}

		fprintf(stdout, "\n%-35s", a[i].address);
		if (i + 1 < n)
		{
			fprintf(stdout, "\n%-35s", a[i + 1].address);
		}

		fprintf(stdout, "\n%-35s", a[i].city);
		if (i + 1 < n)
		{
			fprintf(stdout, "\n%-35s", a[i + 1].city);
		}

		fprintf(stdout, "\n%-35s", a[i].pin);
		if (i + 1 < n)
		{
			fprintf(stdout, "\n%-35s", a[i + 1].pin);
		}
	}

	fprintf(stdout, "\n");

	LINE;
}