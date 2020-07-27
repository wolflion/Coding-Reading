#include<iostream>
using namespace std;

int main()
{
	cout<<"Standard Clib:"<<_STDC_HOSTED_<<endl;//Standard Clib:1
	cout<<"Standard C:"<<_STDC_<<endl;//Standard C:1
	//cout<<"C Standard version:"<<_STDC_VERSION_<<endl;
	cout<<"ISO/IEC"<<_STDC_ISO_10646_<<endl;  //ISO/IEC 200009
}
//g++ -std=c++11 2-1-1.cpp
	