#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1����һ����֪�����������
#if 0
struct Person
{
	char name[64];
	int age;
};

typedef struct Person myPerson;
#endif

//�ȼ���
typedef struct Person
{
	char name[64];
	int age;
}myPerson;

void test01()
{
	struct Person p;
	myPerson p1;//����һ����
}

// ��2�֣�
char* p1, p2;//p1��char*, p2��char����     ��Ҫ�ĳ�char *p1, *p2;//����vs�Ĺ��ɣ�gcc��û��?��
//���������·����������  cout<<typeid(p1).name()<<endl;
// Ϊ�˱������ַ�ʽ ��������typedef
typedef char* pCHAR;  //�⻹��Ҫ�ӷֺŵ�
pCHAR a��b;

// ��3�֣�����ƽ̨��ϸ�ڣ�������ֲ������Aƽ̨�� long long��֧�֣�������typedef
typedef long long LLong;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}