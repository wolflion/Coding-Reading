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
