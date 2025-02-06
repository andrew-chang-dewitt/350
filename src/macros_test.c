#include <stdio.h>

#include "llist.h"
#include "macros/for_each.c"

#define PRINTLN(msg) printf("%s\n", msg);

typedef struct {
  char *name;
  void (*f)(char *);
} a;

a new_a(char *name, void (*f)(char *)) { return (a){name, f}; }

declare_vec(a);

#define A(id, body) void _fn_##id(char *p) body

#define _echo(x) x

#define S(_, ...)                                                              \
  FOR_EACH(_echo, __VA_ARGS__)                                                 \
  int main(int argc, char *argv[argc - 1]) {                                   \
    printf("test");                                                            \
    Vec_a vec = vec_new(a, NULL);                                              \
    /* TODO: this pattern generates the test functions nicely (although it'd   \
     * be great to generate it from a description string instead), however it  \
     * doesn't offer a way of then crawling the arg list again and simply      \
     * extracting the ids for building structs referring to the functions &    \
     * loading them into the appropriate vec for execution*/                   \
    /* To fix this, we can inject the code necessary to insert our test        \
     * objects into the tests vector for processing */                         \
    /* CTEST_CODEGEN ENTRY */                                                  \
    return 0;                                                                  \
  }

S(some_id, A(first, { printf("first arg body"); }),
  A(second, { printf("second arg body"); }),
  A(third, { printf("third arg body"); }),
  A(last, { printf("last arg body"); }))
