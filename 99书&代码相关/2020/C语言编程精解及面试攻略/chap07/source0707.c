// extern storage class
int x = 10; // this is global variable
void one()
{
	extern int x;
	x++;
	printf("\nx in one = %d",x);
}

void two()
{
	extern int x;
	x++;
	printf("\nx in two = %d", x);
}

int main()
{
	extern int x;
	printf("\nx in main = %d", x);
	one();
	two();
}