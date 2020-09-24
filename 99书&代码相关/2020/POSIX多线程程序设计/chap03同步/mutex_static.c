#include <pthread.h>
#include "errors.h"

/*
Declare a structure, with a mutex, statically initialized. This is 
the same as using pthread_mutex_init, with the default attributes.
*/

typedef struct my_struct_tag{
	pthread_mutex_t mutex;  // protects access to value
	int             value;  // Access protected by mutex
}my_struct_t;

my_struct_t data = { PTHREAD_MUTEX_INITALIZER, 0 };

int main(int argc, char* argv[])
{
	return 0;
}