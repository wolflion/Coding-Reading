//
// Created by lionel on 2020/4/22.
//
#include <iostream>
using namespace std;

class PI
{
public:
    double operator* (float v)
    {
        return (double)val*v;  //这里的精度被扩展了
    }
    const float val = 3.1415927f;
};

int main()
{
    //float radius = 1.7e10;
    float radius = 1.0;
    PI pi;
    auto circumference = 2*(pi*radius);

    cout<<circumference<<endl;
}