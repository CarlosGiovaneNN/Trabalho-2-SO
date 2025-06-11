#include "kernel/types.h"
#include "user/user.h"

char *argv0[] = {"code", "20", 0};
char *argv1[] = {"code", "10", 0};
char *argv2[] = {"code", "10", 0};
char *argv3[] = {"code", "30", 0};

int main(int argc, char *argv[]) {


  if (forkwithticket(20) == 0) {
    exec("code", argv0);
  }
  sleep(4);

  if (forkwithticket(10) == 0) {
    exec("code", argv1);  
  }
  sleep(4);

  if (forkwithticket(10) == 0) {
    exec("code", argv2);
  }
  sleep(4);

  if (forkwithticket(30) == 0) {
    exec("code", argv3);
  }
  sleep(4);
  
  exit(0);
}
