/*
 * ��4.4��ʵ�ִ����ӷ�������λ��15λ���ϡ�
 */

#include <iostream>
#include <string.h>
using namespace std;

class BigNumber
{
public:
	BigNumber(string number) //��������ַ������������
	{
		charLength = number.size(); //��ȡ�ַ���
		if (charLength % 4 == 0)  //��4λ����Ϊһ�����㵥Ԫ
		{
			arraySize = charLength / 4;
		}
		else
		{
			arraySize = charLength / 4 + 1;
		}
		data = new int[arraySize];//�����ַ���ת��Ϊ������Ĵ洢����
		for (int i = 0; i < arraySize; i++)  //��ʼ������
		{
			data[i] = 0;
		}
		string::size_type charPointer = charLength - 1;//���岢��ʼ����ȡ�����ַ�ʱ���α�ָ��
		int weight;//���ý�λȨֵ
		for (int i = arraySize; i >= 0; i--)
		{
			weight = 1;
			//���ַ�������λΪ��λת����������������������
			for (int j = 0; j < 4; j++)
			{
				if (charPointer != 0)
				{
					data[i] += (number[charPointer] - '0')*weight;
					weight *= 10;
					charPointer--;
				}
				else
				{
					break;
				}
			}
		}
		data[0] += (number[0] - '0')*weight;
	}

	//���캯��������������������СΪ����
	BigNumber(int s)
	{
		data = new int[s];
		for (int i = 0; i < s;i++)
		{
			data[i] = 0;
		}
		arraySize = s;
	}

	//��������
	~BigNumber()
	{
		delete data;
	}

	//��ȡ��ʾ��������������
	int* getData()
	{
		return data;
	}

	//��ȡ�����С
	int getArraySize()
	{
		return arraySize;
	}

private:
	int *data; //�洢ת�������������
	string::size_type charLength;  //�洢�ַ�������
	int arraySize;  //���������С
};

//�������
void add(BigNumber a, BigNumber b)
{
	//��λ���϶������ֵ��maxNumber
	BigNumber maxNumber = a.getArraySize() >= b.getArraySize() ? a : b;
	//��λ����С������ֵ��minNumber
	BigNumber minNumber = a.getArraySize() < b.getArraySize() ? a : b;

	BigNumber c(maxNumber.getArraySize());//�Խ϶��λ����������C
	int* dataMax = maxNumber.getData(); //��ȡ��������ֵ����
	int* dataMin = minNumber.getData();
	int* dataC = c.getData();

	int i, j;
	int carray = 0; //�����λֵ����ʼ��Ϊ0
	for (i = maxNumber.getArraySize() - 1, j = i - (maxNumber.getArraySize() - minNumber.getArraySize()); i >=0&&j>=0; i--,j--)
	{
		//���������ÿһλ�������������Ҷ������Ӧλ����ټ��Ͻ�λ
		dataC[i] = dataMax[i] + dataMin[j] + carray;
		if (dataC[i]<10000) //���û�н�λ
		{
			carray = 0;
		}
		else
		{
			carray = 1;//��ʾ��һλ
			dataC[i] = dataC[i] - 10000;//��λ����Ӧλ��ֵ��ȥȨֵ
		}
	}

	//���������������Ȳ��ȣ���������
	while (i>=0)
	{
		dataC[i] = dataMax[i] + carray;
		if (dataC[i] < 10000)
		{
			carray = 0;
		}
		else
		{
			carray = 1;
			dataC[i] = dataC[i] - 10000;
		}
		i--;
	}

	//�ж����λ�Ƿ��н�λ����������Ӧ����
	if (carray == 1)
	{
		int* result = new int[c.getArraySize() + 1];
		//������λ�н�λ�������´���һ�����飬��λ�����λΪ1
		result[0] = 1;
		//ԭ���λ��ɴθ�λ��ֵ��ȥȨֵ
		dataC[0] = dataC[0] - 10000;
		//���������е�ʣ��λ��ֵ��ֵ��������
		for (int k = 1; k < c.getArraySize() + 1;k++)
		{
			result[k] = dataC[k - 1];
		}

		//��ӡ������
		for (int i = 0; i < c.getArraySize() + 1;i++)
		{
			if (i>0 && result[i] < 1000)
			{
				cout << '0' << result[i];//��0ռλ
			}
			else
			{
				cout << result[i];
			}
		}
	}
	else
	{
		//���λû�н�λ��ֱ�Ӵ�ӡ������
		for (int i = 0; i < c.getArraySize(); i++)
		{
			if (i>0&&dataC[i]<1000)
			{
				cout << '0' << dataC[i]; //��0ռλ
			}
			else
			{
				cout << dataC[i];
			}
		}
	}
	cout << endl;
	return;
}

//������
int main()
{
	string a1, b1;
	cout << "������Ҫ���������" << endl;
	cin >> a1 >> b1;
	BigNumber a(a1);
	BigNumber b(b1);

	//���Լӷ�
	cout << "a+b�Ľ��Ϊ��" << endl;
	add(a, b);
	return 0;
}


/*
123456789987654321
958746321458796545

�����1008220311144644  --gcc��core����

Ӧ�������10082203111446450866
*/