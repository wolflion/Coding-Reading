// extern storage class
int x; // this is global variable
void one()
{
	x++;
	printf("\nx in one = %d",x);
}

void two()
{
	x++;
	printf("\nx in two = %d", x);
}

int main()
{
	printf("\nx in main = %d", x);
	one();
	two();
}