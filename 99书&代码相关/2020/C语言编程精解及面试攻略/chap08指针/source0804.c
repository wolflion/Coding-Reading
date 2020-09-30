// source04: display array elements using pointers
#include <stdio.h>
int main()
{
	int x[50];
	int i=0;
	char resp='y';
	int *p1,*p2;
	
	p1=&x[0];
	
	while(resp = 'y' || resp == 'Y')
	{
		printf("");
		scanf("%d",&x[i]);
	}
}