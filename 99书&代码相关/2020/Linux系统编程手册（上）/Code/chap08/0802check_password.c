#define  _BSD_SOURCE  // Get getpass() declaration from <unistd.h>
#define _XOPEN_SOURCE  // Get crypt() declaration from <unistd.h>
#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <shadow.h>
#include "../lionel_tlpi.h"

int main(int argc, char *argv[])
{
  char* username, *password, *encrypted, *p;
  struct passwd *pwd;
  struct spwd *spwd;
  //Boolean authOK;
  bool authOK;
  size_t len;
  long lnmax;
  lnmax = sysconf(_SC_LOGIN_NAME_MAX);
  if(lnmax == -1) // If limit is indeterminate
    lnmax = 256;  // make a guess

  username = malloc(lnmax);
  if(username == NULL)
    //errExit("malloc");
    perror("malloc");

  printf("username: ");
}
