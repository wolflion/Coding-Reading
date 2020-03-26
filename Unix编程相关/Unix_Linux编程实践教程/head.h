#include <stdio.h>
#include <sys/shm.h>
#include <time.h>
#include <sys/file.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define oops(m,x) {perror(m);exit(x);}