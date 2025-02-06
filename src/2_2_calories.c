#include <stdio.h>

#ifndef TEST
int main(int argc, char *argv[]) {

  /* Type your code here. */
  char *input = NULL;
  unsigned long len;
  getline(&input, &len, stdin);
  // now just change below to actually parse for value & make calculation
  puts(input);
  return 0;
}
#endif

float calc_calories(int age, int weight, int hr, int time) {
  return ((age * 0.2757 + weight * 0.03295 + hr * 1.0781 - 75.4991) * time) /
         8.368;
}

#ifdef TEST
#define TEST_IMPL_WITH_MAIN
#include "test.h"
#include <string.h>
TEST("strlen returns length of string") {
  ASSERT(strln("") == 0);
  ASSERT(strln("foo") == 3);
}

TEST("[calc_calories] returns correct value") {
  ASSERT(calc_calories(49, 155, 148, 60) == 736.21)
}
#endif
