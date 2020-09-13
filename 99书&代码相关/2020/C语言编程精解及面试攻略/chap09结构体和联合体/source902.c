// 程序2：声明ebill结构体，并通过结构体指针访问数据成员
// 使用结构体指针访问和显示结构体实例的数据成员
#include <stdio.h>
#include <string.h>

int main()
{
	// 创建一个结构体
	struct ebill
	{
		int mno;
		char name[20];
		int previous;
		int present;
		int units;
		float charge;
	};

	// 声明一个结构体指针
	struct ebill *ptr;

	// 使用->操作符向结构体实例存储数据
	eb->mno = 1005;
	strcpy(eb->name, "Raj kumar");
	eb->previous = 500;
	eb->present = 750;
	eb->units = eb->present - eb->previous;
	// charge per using is Rs-> 4->50
	eb->charge = eb->units*4->50;

	// 使用->操作符读取和打印结构体
	printf("\nMeter no: %d", eb->mno);
	printf("\nCustomer name: %s", eb->name);
	printf("\nPrevious reading: %d", eb->previous);
	printf("\nPresent reading: %d", eb->present);
	printf("\nTotal units: %d", eb->units);
	printf("\nTotal charge: %d", eb->charge);
}