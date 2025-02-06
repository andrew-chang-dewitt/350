#include <stdio.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * EXAMPLE TEST FILE
 * -----------------
 * Shows how to declare tests in a single file using TEST
 * & ASSERT macros.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef CMP_TST
#define TEST_IMPL_WITH_MAIN
#include "ctest/lib.h"
SUITE("an example test suite", TEST("1 + 1 = 2, this should pass", {
        int actual = 1 + 1;
        /*ASSERT(actual == 2);*/
        /*
        }),
        TEST("1 + 2 = 2, this should fail") {
          int actual = 1 + 2;
          ASSERT(actual == 2);
        */
      }))

#else

int main(void) {
  printf("not in test mode");
  return 0;
}

#endif
