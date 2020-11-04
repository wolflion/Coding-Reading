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
}