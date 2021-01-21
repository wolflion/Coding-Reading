## 缘起

+ 本章的标题是  chap06：进程

## 内容

### 0

+ 进程结构 、进程虚拟内存的布局和内容、进程的属性。

### 6.1、进程和程序

+ **进程**是由内核定义的抽象的实体，并为该实体分配用以执行程序的各项系统资源。

### 6.2、进程号和父进程号

+ `pid_t getpid(void)`，头文件是`unistd.h`

### 6.3、进程内存布局

+ **图6-1**要烂熟于心
+ **函数要压栈，那么自己`malloc()`就是堆了**，--用这种方法记。

```cpp
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
```



### 6.4、虚拟内存管理

### 6.5、栈和栈帧

### 6.6、命令行参数（argc,argv）

### 6.7、环境列表

+ `export`命令
+ `printenv`命令

#### 从程序中访问环境

+ 程序6-3：显示进程环境

```cpp
#include "../lionel_tlpi.h"
extern char** environ;

int main(int argc, char* argv[])
{
	char** ep;
	for (ep = environ; *ep != NULL; ep++)
		puts(*ep);
	exit(EXIT_SUCCESS);
}

```



#### 修改环境

#### 程序示例

+ 程序6-4：修改进程环境（这个没有run）

```cpp
#define _GNU_SOURCE  // To get various declarations from <stdlib.h>
#include "../lionel_tlpi.h"

extern char** environ;

int main(int argc, char* argv[])
{
	int j;
	char** ep;

	clearenv();  // Erase entire environment

	for (j = 1; j < argc; j++)
	{
		if (putenv(argv[j]) != 0)
			//errExit();
	}

	if (setenv("GREET", "hello world", 0) == -1)
		//errExit();
		;

	unsetenv("BYE");

	for (ep = environ; *ep != NULL; ep++)
		puts(*ep);

	exit(EXIT_SUCCESS);
}

```



### 6.8、执行非局部跳转：setjmp()和longjmp()

+ **非局部（nonlocal）**：是指跳转的目标为当前执行函数之外的某个位置。
+ **`goto`的限制，不能从当前函数跳转到另一函数**。
+ 先通过setjmp()的初始调用建立一个跳转目标，再用switch检测是初次从setjmp()调用返回，还是在调用longjmp()后返回。

```cpp
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
```

+ 对setjmp()函数的使用限制
  + 选择或迭代语句（if、switch、while）
  + 作为独立的函数调用，没有嵌入到更大的表达式之中
+ 滥用longjmp()
  + 线程甲中用了`setjmp()`，却在线程乙中调用`longjmp()`，这是不对的。
+ 优化编译器的问题
  + `longjmp()`操作会使经过优化的变量被赋以错误值
  + `gcc -O`与`gcc`不加编译选项的区别。

```cpp
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
```

+ 尽可能避免使用setjmp()函数和longjmp()函数

### 6.9、总结

### 6.10、练习

## 最后

+ 2021-01-21看了点书，晚上运行了会代码。