﻿/* waitdemo1.c
 * 子进程调用exit是如何触发wait返回父进程的
 * shows how parent pauses until child finishes
 */

#include <stdio.h>

#define DELAY 2

void child_code(int );
void parent_code(int );

int main()
{
	int newpid;

	printf("Before: my pid is %d\n",getpid());

	newpid = fork();
	
	if (newpid == -1)
	{
		perror("fork");
	}
	else if (newpid == 0)
	{
		child_code(DELAY);
	}
	else
	{
		parent_code(newpid);
	}

	return 0;
}


//new process takes a nap and then exits
void child_code(int delay)
{
	printf("child %d here. will sleep for %d seconds\n", getpid(), delay);
	sleep(delay);
	printf("child done. about to exit\n");
	exit(17);
}

//parent waits for child then prints a message
void parent_code(int childpid)
{
	int wait_rv;  //return value form wait()
	wait_rv = wait(NULL);
	printf("done waiting for %d. Wait returned: %d\n", childpid, wait_rv);
}