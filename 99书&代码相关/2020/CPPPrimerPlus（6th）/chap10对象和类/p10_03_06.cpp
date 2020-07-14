#include <iostream>
using namespace std;

class Stock
{
public:
	Stock(int num, double price)
	{
		m_num = num;
		m_price = price;
	}
	void show()
	{
		cout << "num and price is " << m_num << "-" << m_price << endl;
	}

	void show1() const
	{
		cout << "num and price is " << m_num << "-" << m_price << endl;
	}
private:
	int m_num;
	double m_price;
};

void test()
{
	const Stock stock01 = { 01, 20.4 };//C++11��д��

	const Stock stock11(11, 200.4);
	//stock11.show();  //IDEֱ�Ӿ���ʾ������������Ա���������ݵ������޶���������������const Stock��
	stock11.show1();
}

int main()
{
	test();
	cin.get();
	return 0;
}
