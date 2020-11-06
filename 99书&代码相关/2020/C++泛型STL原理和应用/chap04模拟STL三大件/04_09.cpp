#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int num;
	vector<char>vec_A(8);

	cout << "��vec_A����ַ�A:" << endl;
	fill(vec_A.begin(), vec_A.end(),'A');
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "��������vec_B��ʹ���ַ�B��ʼ��:" << endl;
	char array_B[] = { 'B','B', 'B', 'B' };
	vector<char>vec_B(array_B, array_B + 4);
	for_each(vec_B.begin(), vec_B.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "��vec_A��2��λ�ÿ�ʼ��vec_B���ݸ���:" << endl;
	copy(vec_B.begin(),vec_B.end(),vec_A.begin()+2);
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "�Ƴ�vec_A����Ԫ��:" << endl;
	vector<char>::iterator it;
	it = remove(vec_A.begin(), vec_A.end(), 'A');
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "ɾ������Ԫ��" << endl;
	vec_A.erase(it, vec_A.end());
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "���ַ�c�滻����Ԫ��B:" << endl;
	// error "Expression: cannot seek vector iterator after end"
	//replace(vec_A.begin(), vec_A.end() + 2, 'B', 'C');
	replace(vec_A.begin(), vec_A.begin() + 2, 'B', 'C'); // ����дendʱ����Խ���
	replace(vec_B.begin(), vec_B.end(), 'B', 'X');
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "��������Ԫ��:" << endl;
	vec_A.insert(vec_A.begin(), 'D');
	vec_A.insert(vec_A.end(), 'A');
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "����" << endl;
	sort(vec_A.begin(), vec_A.end());
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "����vec_C��ʹ���С����vec_A.size()+vec_B:" << endl;
	vector<char>vec_C(vec_A.size() + vec_B.size());

	cout << "vec_A��vec_B�ϲ�����vec_C:" << endl;
	merge(vec_A.begin(), vec_A.end(), vec_B.begin(), vec_B.end(), vec_C.begin());
	for_each(vec_A.begin(), vec_A.end(), [](char c) {cout << c << " "; });
	cout << endl;
	cout << endl;

	cout << "ͳ��vec_C���ַ�B����Ŀ:" << endl;
	num = count(vec_C.begin(), vec_C.end(), 'B');
	cout << num << endl;
	return 0;
}