#include <iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Name
{
public:
	Name(const char* myp)
	{
		int len = strlen(myp);
		p = (char*)malloc(len + 1);
		strcpy(p, myp);
	}
protected:
	~Name()
	{
		if (p)
		{
			free(p);
			p = NULL;
			len = 0;
		}
	}
private:
	char *p;
	int len;
};

void objplay()
{
	Name obj1("123");
	Name obj2 = obj1;  //拷贝构造函数，没有实现。用编译器默认的，是个浅拷贝【指针变量指向的空间，没有分配】
}

int main(int argc, char** argv)
{
	objplay();

	getchar();
	return 0;
}