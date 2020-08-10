//写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。

#include <string>
#include <iostream>
//#include <sstream>
using namespace std;

int main()
{
    double dInput;
    cin >> dInput;

    //直接加0.5转整型即可。
    int iOutput = static_cast<int>(dInput + 0.5);
    cout<<iOutput<<endl;


#if 0
    stringstream oss;
    oss<<i;
    string s = oss.str();
#endif
}

// 方法1：直接加 0.5 比较简单；不用再其它转来转去；
// 方法2：double转成 string，然后再分割'.'，可以用来扩充一下