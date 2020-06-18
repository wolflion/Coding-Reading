/*
 * 例4.4、实现大数加法，大数位在15位以上。
 */

#include <iostream>
#include <string.h>
using namespace std;

class BigNumber
{
public:
	BigNumber(string number) //以输入的字符串构造大数据
	{
		charLength = number.size(); //获取字符数
		if (charLength % 4 == 0)  //以4位数字为一个计算单元
		{
			arraySize = charLength / 4;
		}
		else
		{
			arraySize = charLength / 4 + 1;
		}
		data = new int[arraySize];//建立字符串转化为整数后的存储数组
		for (int i = 0; i < arraySize; i++)  //初始化数组
		{
			data[i] = 0;
		}
		string::size_type charPointer = charLength - 1;//定义并初始化获取单个字符时的游标指针
		int weight;//设置进位权值
		for (int i = arraySize; i >= 0; i--)
		{
			weight = 1;
			//将字符串以四位为单位转化成整数并存入整型数组
			for (int j = 0; j < 4; j++)
			{
				if (charPointer != 0)
				{
					data[i] += (number[charPointer] - '0')*weight;
					weight *= 10;
					charPointer--;
				}
				else
				{
					break;
				}
			}
		}
		data[0] += (number[0] - '0')*weight;
	}

	//构造函数，以所需的整数数组大小为参数
	BigNumber(int s)
	{
		data = new int[s];
		for (int i = 0; i < s;i++)
		{
			data[i] = 0;
		}
		arraySize = s;
	}

	//析构函数
	~BigNumber()
	{
		delete data;
	}

	//获取表示大数的整型数组
	int* getData()
	{
		return data;
	}

	//获取数组大小
	int getArraySize()
	{
		return arraySize;
	}

private:
	int *data; //存储转化后的整型数组
	string::size_type charLength;  //存储字符串长度
	int arraySize;  //整型数组大小
};

//大数相加
void add(BigNumber a, BigNumber b)
{
	//将位数较多的数赋值给maxNumber
	BigNumber maxNumber = a.getArraySize() >= b.getArraySize() ? a : b;
	//将位数较小的数赋值给minNumber
	BigNumber minNumber = a.getArraySize() < b.getArraySize() ? a : b;

	BigNumber c(maxNumber.getArraySize());//以较多的位数创建大数C
	int* dataMax = maxNumber.getData(); //获取大数的数值数组
	int* dataMin = minNumber.getData();
	int* dataC = c.getData();

	int i, j;
	int carray = 0; //定义进位值，初始化为0
	for (i = maxNumber.getArraySize() - 1, j = i - (maxNumber.getArraySize() - minNumber.getArraySize()); i >=0&&j>=0; i--,j--)
	{
		//结果大数的每一位等于两个大数右对齐的相应位相加再加上进位
		dataC[i] = dataMax[i] + dataMin[j] + carray;
		if (dataC[i]<10000) //如果没有进位
		{
			carray = 0;
		}
		else
		{
			carray = 1;//表示进一位
			dataC[i] = dataC[i] - 10000;//进位后相应位的值减去权值
		}
	}

	//如果两个相加数长度不等，继续计算
	while (i>=0)
	{
		dataC[i] = dataMax[i] + carray;
		if (dataC[i] < 10000)
		{
			carray = 0;
		}
		else
		{
			carray = 1;
			dataC[i] = dataC[i] - 10000;
		}
		i--;
	}

	//判断最高位是否有进位，并做出相应处理
	if (carray == 1)
	{
		int* result = new int[c.getArraySize() + 1];
		//如果最高位有进位，则重新创建一个数组，进位后最高位为1
		result[0] = 1;
		//原最高位变成次高位，值减去权值
		dataC[0] = dataC[0] - 10000;
		//将老数组中的剩余位的值赋值给新数组
		for (int k = 1; k < c.getArraySize() + 1;k++)
		{
			result[k] = dataC[k - 1];
		}

		//打印计算结果
		for (int i = 0; i < c.getArraySize() + 1;i++)
		{
			if (i>0 && result[i] < 1000)
			{
				cout << '0' << result[i];//用0占位
			}
			else
			{
				cout << result[i];
			}
		}
	}
	else
	{
		//最高位没有进位则直接打印计算结果
		for (int i = 0; i < c.getArraySize(); i++)
		{
			if (i>0&&dataC[i]<1000)
			{
				cout << '0' << dataC[i]; //用0占位
			}
			else
			{
				cout << dataC[i];
			}
		}
	}
	cout << endl;
	return;
}

//主函数
int main()
{
	string a1, b1;
	cout << "输入需要计算的数字" << endl;
	cin >> a1 >> b1;
	BigNumber a(a1);
	BigNumber b(b1);

	//测试加法
	cout << "a+b的结果为：" << endl;
	add(a, b);
	return 0;
}


/*
123456789987654321
958746321458796545

输出：1008220311144644  --gcc上core掉了

应该输出：10082203111446450866
*/