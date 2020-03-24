#include <unistd.h>
#include <stdio.h>

int main()
{
	int i = 0;
	alarm(1);
	while (true)
	{
		printf("%d\n", i++);
	}
	return 0;
}