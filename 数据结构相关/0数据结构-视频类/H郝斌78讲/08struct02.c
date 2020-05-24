#include <stdio.h>
#include <string.h>

struct Student
{
	int sid;
	char name[200];
	int age;
};

int main(void)
{
	struct Student st = { 1000, "zhangsan", 20 }; 

	//第一种 st.sid = 99;

	//一般使用第2种方式
	struct Student *pst; //指针占4个字节，应该地址总线是32根的，32/8=4。
	pst = st;
	pst->sid = 99; //pst->sid 等价于 (*pst).sid。 而(*pst).sid等价于 st.sid。 所以 pst->sid 等价于 st.sid


	return 0;
}