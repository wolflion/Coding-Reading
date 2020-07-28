#include <climits>
#include <cstdio>
using namespace std;

int main()
{
	long long ll_min = LLONG_MIN;
	long long ll_max = LLONG_MAX;
	unsigned long long ull_max = ULLONG_MAX;
	
	printf("min of long long: %lld\n", ll_min); // min of long long: 
	printf("max of long long: %lld\n", ll_max); // max of long long:
	printf("max of unsigned long long: %lld\n",ull_max); // max of unsigned long long:
}

// g++ -std=c++11 2-2-1.cpp