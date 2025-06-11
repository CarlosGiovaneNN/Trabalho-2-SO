#include "kernel/types.h"
#include "user/user.h"

char *argv0[] = {"code", "0", 0};
char *argv1[] = {"code", "1", 0};
char *argv2[] = {"code", "2", 0};
char *argv3[] = {"code", "3", 0};

int main(int argc, char *argv[]) {


  if (forkwithticket(0) == 0) {
    exec("code", argv0);
  }
  sleep(4);

  if (forkwithticket(1) == 0) {
    exec("code", argv1);  
  }
  sleep(4);

  if (forkwithticket(2) == 0) {
    exec("code", argv2);
  }
  sleep(4);

    if (forkwithticket(3) == 0) {
    exec("code", argv3);
  }
  sleep(4);
  
  exit(0);
}
