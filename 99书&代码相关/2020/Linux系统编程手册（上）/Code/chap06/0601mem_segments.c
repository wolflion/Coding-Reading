#include "../lionel_tlpi.h"

char globBuf[65535];  //uninitialized data segment
int primes[] = { 2,3,5,7 };//initialized data segment

static int square(int x)  // allocated in frame for square()
{
	int result;
	result = x * x;
	return result;   // return value passed via register
}

static void doCal(int val)
{
	printf("The square of %d is %d\n",val,square(val));

	if (val < 1000)
	{
		int t;  // allocated in frame for doCal()
		t = val * val * val;
		printf("The cube of %d is %d\n",val,t);
	}
}

int main(int argc, char** argv[])   // allocated in frame for main()
{
	static int key = 9973;//initialized data segment
	static char mbuf[10240000];//uninitialized data segment
	char* p; // allocated in frame for main()

	p = malloc(1024);//Points to memory in heap segment
	doCal(key);
	exit(EXIT_SUCCESS);
}

/*
* 这个重点，应该不是运行，不同的变量在哪个区才是王道
root@raspberrypi:~/lionel/2021Code/chap06# gcc 0601mem_segments.c
root@raspberrypi:~/lionel/2021Code/chap06# ./a.out
The square of 9973 is 99460729
*/