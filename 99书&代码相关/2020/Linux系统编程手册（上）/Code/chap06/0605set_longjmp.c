#include <setjmp.h>
//#include<stdio.h>
#include "../lionel_tlpi.h"

static jmp_buf env;

static void f2(void)
{
	longjmp(env, 2);
}

static void f1(int argc)
{
	if (argc == 1)
		longjmp(env, 1);
	f2();
}

int main(int argc, char* argv[])
{
	int i = setjmp(env); // 我自己写的，原文是switch(setjmp(env))
	switch (i)
	{
	case 0:    // This is the return after the initial setjmp()
		printf("Calling f1() after initial setjmp()\n");
		f1(argc);  // never returns...
		break;  // but this is good form

	case 1:
		printf("We jumped back from f1()\n");
		break;

	case 2:
		printf("We jumped back from f2()\n");
		break;
	}
	exit(EXIT_SUCCESS);   //stdlib.h里的
}

/*
* run
* 
root@raspberrypi:~/lionel/2021Code/chap06# gcc 0605set_longjmp.c 
root@raspberrypi:~/lionel/2021Code/chap06# ls
0605set_longjmp.c  a.out
root@raspberrypi:~/lionel/2021Code/chap06# ./a.out 
Calling f1() after initial setjmp()
We jumped back from f1()

指定命令行参数
root@raspberrypi:~/lionel/2021Code/chap06# ./a.out a
Calling f1() after initial setjmp()
We jumped back from f2()
*/