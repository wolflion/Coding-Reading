/* forkdemo2.c
 * 子进程创建进程。【子进程不是从main函数的开始，而是从fork返回的地方开始它的生命之旅】
 * shows how child processes pick up at the return
 * from fork() and can execute any code they like,
 * even fork(). Predict number of lines of output.
 */

#include <stdio.h>

int main()
{
	printf("my pid is %d\n",getpid());

	fork();
	fork();
	fork();

	printf("my pid is %d\n", getpid());
}
