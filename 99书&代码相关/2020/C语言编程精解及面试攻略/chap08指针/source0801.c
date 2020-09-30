// understanding pointers
#include <stdio.h>
int main()
{
	// take int type variable
	int v = 15;

	// take int type pointer
	int *pv;

	// store memory address of v in pv
	pv = &v;
	printf("\nvalue of v = %d", v);
	printf("\nvalue of pv = %u", pv);
	printf("\nvalue of *pv = %d", pv);
}