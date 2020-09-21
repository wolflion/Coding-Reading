// global or local?
int x = 10;// this is global variable
void one()
{
	int x = 20; // this is local variable
	printf("\nx in one=%d",x);
}

void two()
{
	extern int x; // again this refers to global variable
	printf("\nx in two = %d",x);
}

int main()
{
	extern int x; // refers to global variable
	printf("\nx in main=%d",x);
	one();
	two();
}