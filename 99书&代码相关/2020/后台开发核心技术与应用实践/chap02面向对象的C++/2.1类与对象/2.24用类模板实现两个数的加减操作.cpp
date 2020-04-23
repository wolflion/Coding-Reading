#include<iostream>
using namespace std;

template<typename T>  //当然用<class T>也没有问题
class Operation
{
	public:
	Operation(T a, T b):x(a),y(b){}
	T add()  //类外定义的话  T Operation <T>::add()
	{
		return x+y;
	}
	T subtract()
	{
		return x-y;
	}
	private:
	T x,y;
};

int main()
{
	Operation <int> op_int(1,2);
	cout<<op_int.add()<<" "<<op_int.subtract()<<endl;//输出3 -1
	Operation <float> op_double(1.2,2.3);
	cout<<op_double.add()<<" "<<op_double.subtract()<<endl;//输出3.5 -1.1
}