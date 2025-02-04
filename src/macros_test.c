#include <stdio.h>

#include "macros/for_each.c"

#define PRINTLN(msg) printf("%s\n", msg);

int main(int argc, char *argv[argc - 1]) {
  PRINTLN("this just prints the given message")
  PRINTLN("see?")

  FOR_EACH(PRINTLN, "this prints multiple messages", "I can give it a bunch",
           "& it will print each on", "their own line", "because why not?")

  return 0;
}
