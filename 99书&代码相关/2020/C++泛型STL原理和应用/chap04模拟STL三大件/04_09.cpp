#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int num;
	vector<char>vec_A(8);

	cout << "向vec_A填充字符A:" << endl;
	fill(vec_A.begin(), vec_A.end(),'A');
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "定义容器vec_B并使用字符B初始化:" << endl;
	char array_B[] = { 'B','B', 'B', 'B' };
	vector<char>vec_B(array_B, array_B + 4);
	for_each(vec_B.begin(), vec_B.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "从vec_A第2个位置开始用vec_B内容复制:" << endl;
	copy(vec_B.begin(),vec_B.end(),vec_A.begin()+2);
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "移除vec_A数据元素:" << endl;
	vector<char>::iterator it;
	it = remove(vec_A.begin(), vec_A.end(), 'A');
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;
}