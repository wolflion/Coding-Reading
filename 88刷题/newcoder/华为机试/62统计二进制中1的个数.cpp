// https://blog.csdn.net/qq_34068668/article/details/77962886
// 计算整数二进制中1的个数
#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

list<int>L;
void BinaryVector(int n)
{
	int temp;
	temp = n;
	
	while (temp != 0)
	{
		L.push_front(temp % 2);
		temp = temp >> 1;
	}
}

int findNumberOf1(int num)
{
	int iCount = 0;
	// 转成2进制的函数
	//char binary[2560];
	// itoa(num, binary, 2);---这是windows特有的
	//sprintf_s(binary, "%x", num);
	BinaryVector(num);
	for (auto it = L.begin(); it != L.end();it++)
	{
		if (*it == 1)
			iCount++;
	}

	return iCount;
}

// 这是抄的人家的思路，自已开始不是这么想的 -- 提交的代码，是这个方式，通过的。【要继续学习一下】
int countOne(int num)  
{  
    int count = 0;  
    while ( num )  
    {  
        if( num & 1 ){  
            ++count;  
        }  
        num >>= 1;  
    }  
    return count;  
}  

int main()
{
	int i;
	while (cin >> i)
	{
		printf("%d\n", findNumberOf1(i));
	}
	return 0;
}