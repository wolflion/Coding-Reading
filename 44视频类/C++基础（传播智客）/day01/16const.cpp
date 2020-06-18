void main()
{
	const int a = 10;  //好像a是一个常量，其实不然
	//a=11;//这个会报错

	int *p = NULL;
	p = &a;
	*p = 20;//这个时候，a还是10
	printf("a=%d", a);     //输出10
	printf("*p=%d", *p);  //输出20
}