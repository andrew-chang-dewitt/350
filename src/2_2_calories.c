#include <stdio.h>

int main(int argc, char *argv[]) {

  /* Type your code here. */
  char *input = NULL;
  unsigned long len;
  getline(&input, &len, stdin);
  // now just change below to actually parse for value & make calculation
  puts(input);
  return 0;
}
