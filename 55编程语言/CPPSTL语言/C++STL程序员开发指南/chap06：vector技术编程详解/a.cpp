#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
//#pragma warning(disable:4786)  //添加避免告警的语句
using namespace std;

class AVector {
public:
	void init();
	void initValue();
	void getSize();
	void useIterator();
	void useFind();
};

void AVector::init()
{
	// 6-1：vector定义实例
	std::vector<std::string> Myvector;  // 因为前面有写了using语句，可以写成vector<string>模板类，这样。
	cout << __FUNCTION__ << "Myvector" << endl;
}

void AVector::initValue()
{
	// 实例6-4：vector初始化实例
	vector<string> Myvector;
	Myvector.push_back("Chocolate");
	Myvector.push_back("Strawberry");
	Myvector.push_back("Lime");
	Myvector.push_back("Vanilla");
	for (int i = 0; i < 4; i++)
	{
		cout << Myvector[i] << " ";
	}
	cout << endl;

	// 实例6-5：vector初始化实例
	vector<int> iVec;
	cout << __FUNCTION__ << iVec.size() << iVec.capacity() << endl;// 刚定义的时候，2个都是0
	//iVec.reserve(4);
	iVec.resize(4);  // 书中这行写错了，被我注释掉了。会报“vector subscript out of range”
	cout << __FUNCTION__ << iVec.size() << iVec.capacity() << endl;
	for (size_t i = 0; i < 4; i++)  //原书用的是unsigned int，只不过我习惯 size_t代替了
	{
		iVec[i] = i;
		cout << iVec[i]  << " ";
	}
	cout << endl;
}

void AVector::getSize()
{
	typedef vector<int> INTVECTOR;  // 这个要学着点，偷懒才能进步
	INTVECTOR iVec;
	iVec.push_back(42);
	// 1, 1073741823, 1
	cout << __FUNCTION__ << iVec.size() << iVec.max_size() << iVec.capacity() << endl;
	iVec.reserve(1000);
	// 1, 1073741823, 1000
	cout << __FUNCTION__ << iVec.size() << iVec.max_size() << iVec.capacity() << endl;
	iVec.resize(2000);
	// 2000, 1073741823, 1000
	cout << __FUNCTION__ << iVec.size() << iVec.max_size() << iVec.capacity() << endl;
}

void AVector::useIterator()
{

}

void AVector::useFind()
{
	// 实例6-14：通用算法find()使用实例
	vector<string> Fruit;  // 作者用的是vector<char*>的，但push_back("apple")，怎么push_back()不报错的呢？
	vector<string>::iterator FruitIterator;
	Fruit.push_back("Apple");
	Fruit.push_back("Pineapple");
	Fruit.push_back("Star Apple");
	FruitIterator = find(Fruit.begin(), Fruit.end(), "Pineapple");
	if (FruitIterator == Fruit.end())
	{
		cout << "Fruit not found in vector" << endl;
	}
	else
	{
		cout << *FruitIterator << endl;
	}
}

int main()
{
	AVector a;
	a.init();
	a.initValue();
	a.getSize();
	a.useFind();
}
