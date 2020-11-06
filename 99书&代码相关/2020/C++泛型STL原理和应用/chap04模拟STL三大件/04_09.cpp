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

	cout << "删除数据元素" << endl;
	vec_A.erase(it, vec_A.end());
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "用字符c替换数据元素B:" << endl;
	// error "Expression: cannot seek vector iterator after end"
	//replace(vec_A.begin(), vec_A.end() + 2, 'B', 'C');
	replace(vec_A.begin(), vec_A.begin() + 2, 'B', 'C'); // 这里写end时，会越界错
	replace(vec_B.begin(), vec_B.end(), 'B', 'X');
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "插入数据元素:" << endl;
	vec_A.insert(vec_A.begin(), 'D');
	vec_A.insert(vec_A.end(), 'A');
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "排序" << endl;
	sort(vec_A.begin(), vec_A.end());
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "定义vec_C并使其大小等于vec_A.size()+vec_B:" << endl;
	vector<char>vec_C(vec_A.size() + vec_B.size());

	cout << "vec_A和vec_B合并输入vec_C:" << endl;
	merge(vec_A.begin(), vec_A.end(), vec_B.begin(), vec_B.end(), vec_C.begin());
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "统计vec_C中字符B的数目:" << endl;
	num = count(vec_C.begin(), vec_C.end(), 'B');
	cout << num << endl;
	return 0;
}