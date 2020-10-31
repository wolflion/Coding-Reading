// 例7-14：在remove_if中验证greater_1的正确性
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 一元函数对象类
template <typename _Tp>
struct greater_1 :public binary_function<_Tp, _Tp, bool>
{
	_Tp value; //常量
	greater_1(_Tp v)   //构造函数
	{
		value = v;
	}

	bool operator()(const _Tp& __x)const
	{
		return __x > value;
	}
};


int main()
{
	//定义一个向量并初始化
	vector<int> Vect{ 900,100,20,300,4,200,250 };
	//显示向量初始化结果
	cout << "显示向量初始化结果" << endl;
	for_each(Vect.begin(), Vect.end(), [](int n)
		{
			cout << ' ' << n;
		});

	cout << endl << endl;
	vector<int>::iterator it;

	//移出向量中所有大于100的元素
	it = remove_if(Vect.begin(), Vect.end(), greater_1<int>(100));

	// 显示移出操作后向量内容
	cout << "移出操作后应该保存内容为：" << endl;
	
	for_each(Vect.begin(), Vect.end(), [](int n)
		{cout << ' ' << n; });

	return 0;
}