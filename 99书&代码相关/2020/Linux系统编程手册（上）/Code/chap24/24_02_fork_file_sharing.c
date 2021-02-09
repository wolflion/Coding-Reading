#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include"../lionel_tlpi.h"

int main(int argc, char *argv[])
{
    int fd, flags;
    char template[] = "tmp/test2402";

    setbuf(stdout,NULL);  // Disable buffering of stdout

    fd = mkstemp(template);
    if(fd == -1)
        //errExit("mkstemp");

    printf("File offset before fork(): %lld\n",
            (long long)lseek(fd,0,SEEK_CUR));

    flags = fcntl(fd,F_GETFL);
    if(fd == -1)
        //errExit("fcntl - F_GETFL");
    printf("O_APPEND flag before fork() is : %s\n",
            (flags&O_APPEND)?"on":"off");
    
    switch (fork())
    {
    case -1:
        // errEixt("fork");
    case 0:  //Child: change file offset and status flags
        if(lseek(fd,1000,SEEK_SET) == -1)
            //errExit("lseek");

        flags = fcntl(fd,F_GETFL);  // Fetch current flags
        if(flags == -1)
            //errExit("fcntl - F_GETFL");
        flags |= O_APPEND;  // Turn O_APPEND on
        if(fcntl(fd,F_SETFL,flags) == -1)
            //errExit("fcntl - F_GETFL");
        _exit(EXIT_SUCCESS);
    
    default: // Parent: can see file changes made by child
        if(wait(NULL) == -1)
            //errExit("wait");    // Wait for child eixt
        printf("Child has exited\n");

        printf("File offset in parent: %lld\n",
            (long long)lseek(fd,0,SEEK_CUR));

        flags = fcntl(fd,F_GETFL); 
        if(flags == -1)
            //errExit("fcntl - F_GETFL");
        printf("O_APPEND flag in parent is :%s\n",
                (flags & O_APPEND)?"on":"off");
        exit(EXIT_SUCCESS);
    }
}

/*
root@raspberrypi:/home/Code/C# ./a.out 
File offset before fork(): -1
O_APPEND flag before fork() is : on
File offset in parent: -1
O_APPEND flag in parent is :on
*/