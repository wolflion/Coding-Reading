#include <stdio.h>

#define LOG(...) {\
    fprintf(stderr,"%s: Line %d:\t",__FILE__, __LINE__);\
	fprintf(stderr, __VA_ARGS__);\
	fprintf(stderr,"\n");\
}

int main()
{
	int x = 3;
	//一些代码
	LOG("x=%d",x);//2-1-4.cpp  Line 13 x = 3 
}

//g++ -std=C++11 2-1-4.cpp