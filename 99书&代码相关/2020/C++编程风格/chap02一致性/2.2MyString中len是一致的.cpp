#include <string.h>
#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()
	{
		s = new char[80];
		len = 80;
	}

	MyString(int n)
	{
		s = new char[n];
		len = n;
	}

	MyString(char *p)
	{
		len = strlen(p);
		s = new char[len + 1];  //这里为啥要加1，难道是strlen()没有加\0?
		strcpy(s, p);
	}

	MyString(MyString &str);
	~MyString()
	{
		delete[] s;
	}

	void assign(char *str)
	{
		strcpy(s, str);
		len = strlen(str);
	}

	void print()
	{
		cout << s << "\n";
	}

	void connect(MyString& a, MyString& b);

private:
	char *s;
	int len;
};

MyString::MyString(MyString &str)
{
	len = str.len;
	s = new char[len];
	strcpy(s, str.s);
}

void MyString::connect(MyString& a, MyString& b)
{
	len = a.len + b.len;
	s = new char[len];
	strcpy(s, a.s);
	strcat(s, b.s);
}

int main()
{
	char *str = "The wheel that squeaks the loudest\n";
	MyString a(str), b, author("Josh Billings\n"), both, quote;
	b.assign("Is the one that gets the grease\n");
	both.connect(a, b);
	quote.connect(both, author);
	quote.print();
}