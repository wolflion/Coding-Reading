//公鸡5元，母鸡3元，小鸡3只1元；100块买100只鸡

#include "../head.h"
const int iValue = 100;
const int iNum = 100;

int main()
{
	int iHenNum,iCockNum,iChickNum;//母鸡hen，公鸡cock，小鸡chick
	for (iHenNum = 0; iHenNum <= 20; iHenNum++)
	{
		for (iCockNum = 0; iCockNum <= 33; iCockNum++)
		{
			/* 我的代码
			for (iChickNum = 0; iChickNum < 100; iChickNum++)
			{
				if (iHenNum*5+iCockNum*3+(iChickNum/3)*1 == 100 && iHenNum+iCockNum+iChickNum == 100)
				{
					printf("%d-%d-%d\n", iHenNum, iCockNum, iChickNum);
				}
			}
			*/

			//书上的代码
			iChickNum = iNum - iCockNum - iHenNum;
			if (iChickNum % 3 == 0 && iHenNum * 5 + iCockNum * 3 + (iChickNum / 3)==iValue)
			{
				printf("%d-%d-%d\n", iHenNum, iCockNum, iChickNum);
			}
		}
	}
	return 0;
}

/*
 * 我的结果：
 0-25-75
 3-20-77
 4-18-78
 7-13-80
 8-11-81
 11-6-83
 12-4-84
 */