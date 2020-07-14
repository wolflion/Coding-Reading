//stock00.cpp -- implementing the Stock class
//version 00
#include <iostream>
using namespace std;
#include "stock00.h"

void Stock::acquire(const std::string &co, long n, double pr)
{
	company co;
	if(n < 0)
	{
		cout<<"Number of shares can't be negative;"
		<<company<<"shares set to 0.\n";
		shares = 0;
	}
	else
	{
		shares = n;
		share_val = pr;
		set_tot();
	}
}

void 

