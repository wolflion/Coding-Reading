#include <string>
using namespace std;

class A
{
public:
	A(const string &s){ ; }
	string f(){ return "hello world"; }
};

class B : public A
{
public:
	B() :A(s = f()){}  // 这行有问题。
private:
	string s;
};

int main()
{
	B b;
}