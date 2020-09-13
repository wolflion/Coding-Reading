// 程序1：创建一个包含多种类型成员的ebill结构体
// 使用结构体显示电子账单
#include <stdioh>
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

	// 声明ebill类型变量eb
	struct ebill eb;

	// 将数据存储到结构体变量的数据成员中
	eb.mno = 1005;
	strcpy(eb.name, "Raj kumar");
	eb.previous = 500;
	eb.present = 750;
	eb.units = eb.present - eb.previous;
	// charge per using is Rs. 4.50
	eb.charge = eb.units*4.50;

	// 从结构体实例中读取数据并显示之
	printf("\nMeter no: %d", eb.mno);
	printf("\nCustomer name: %s", eb.name);
	printf("\nPrevious reading: %d", eb.previous);
	printf("\nPresent reading: %d", eb.present);
	printf("\nTotal units: %d", eb.units);
	printf("\nTotal charge: %d", eb.charge);
}