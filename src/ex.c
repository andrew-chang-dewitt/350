#include <stdio.h>

#ifdef CMP_TST
#define TEST_IMPL_WITH_MAIN
#include "test.h"

#else

int main(void) {
  printf("not in test mode");
  return 0;
}

#endif
