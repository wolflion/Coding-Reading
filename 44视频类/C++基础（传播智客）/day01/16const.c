void main()
{
	const int a = 10;  //好像a是一个常量，其实不然
	//a=11;//这个会报错

	int *p = NULL;
	p = &a;

	//p=(int*)&a;

	*p = 20;//这个时候，a就是20了   【间接赋值】
	printf("a=%d", a); 
	printf("*p=%d", *p);
}