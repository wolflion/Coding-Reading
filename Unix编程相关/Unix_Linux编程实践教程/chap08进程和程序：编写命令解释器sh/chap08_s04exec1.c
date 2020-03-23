/*exec1.c  - shows how easy it is for a program to run a program
 */

#include <unistd.h>

int main()
{
	char *arglist[3];
	arglist[0] = "ls";
	arglist[1] = "-l";
	arglist[0] = 0;  //最后一个元素必须是null
	printf("*** About to exec ls -l \n");
	execvp("ls", arglist);
	printf("*** ls is done. bye\n");  //这个消息不会被打印出来的。【需要自己知道啥原因】
}