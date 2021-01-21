#include <setjmp.h>
#include "../lionel_tlpi.h"

static jmp_buf env;

static void doJump(int nvar, int rvar, int vvar)
{
	printf("Inside doJmp(): nvar=%d rvar=%d vvar=%d\n",nvar,rvar,vvar);
	longjmp(env, 1);
}

int main()
{
	int nvar;
	register int rvar;  // allocated in register if possible
	volatile int vvar;  // see text

	nvar = 111;
	rvar = 222;
	vvar = 333;

	if (setjmp(env) == 0)  // Code executed after setjmp()
	{
		nvar = 777;
		rvar = 888;
		vvar = 999;
		doJump(nvar, rvar, vvar);
	}
	else {
		printf("After doJmp(): nvar=%d rvar=%d vvar=%d\n", nvar, rvar, vvar);
	}
	exit(EXIT_SUCCESS);
}

/*
* 非优化的方式编译
root@raspberrypi:~/lionel/2021Code/chap06# gcc 0606setjmp_vars.c 
root@raspberrypi:~/lionel/2021Code/chap06# ./a.out 
Inside doJmp(): nvar=777 rvar=888 vvar=999
After doJmp(): nvar=777 rvar=222 vvar=999

优化的方式
root@raspberrypi:~/lionel/2021Code/chap06# gcc -O 0606setjmp_vars.c
root@raspberrypi:~/lionel/2021Code/chap06# ./a.out
Inside doJmp(): nvar=777 rvar=888 vvar=999
After doJmp(): nvar=111 rvar=222 vvar=999

gcc -Wall -Wextra -O 的方式编译
*/