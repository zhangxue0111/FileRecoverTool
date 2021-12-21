#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  // int i;

  if(argc < 2) {
    directoryWalker(".");
    exit();
  }
  if(directoryWalker(argv[1]) < 0) {
    printf(2, "usage: directoryWalker...\n");
    exit();
  }
  exit();
}
