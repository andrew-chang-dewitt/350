#ifndef CTEST_LIB_H
#define CTEST_LIB_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../llist.h"
#include "../result.h"

typedef struct {
} Empty;

typedef struct {
  char *test;
  char *assertion;
  char *file;
  int line;
} Failure;

DEFINE_RESULT(Empty, Failure, TestResult)

typedef struct {
  char *name;
  char *file;
  TestResult (*run)();
} Test;

declare_vec(Test);

declare_vec(Failure);

typedef struct {
  int pass;
  Vec_Failure failures;
} Report;

// // TODO: define these now so that tests will get registered & their bodies
// will
// // be called by Node->exec()
//
// // replace test w/ function that registers test onto an object
// // struct Node {
// //   struct Node *next;
// //   struct Node *prev;
// //   TestResult (*exec)();
// //   char *file;
// //   char *name;
// // };
// #define TEST(name, fn) \
//   _list_append(&root, { \
//                           .name = name, \
//                           .exec = fn, \
//                           .file = __FILE__, \
//                       })
//
// #define ASSERT(ast) \
//   // TODO: need to somehow give an id to this function? not sure what to
//   do...
// //   do { \
// //     assertion = #ast; \
// //     file = __FILE__; \
// //     line = __LINE__; \
// //     if (ast) { \
// //       putchar('.'); \
// //     } else { \
// //       putchar('F'); \
// //     } \
// //   } while (0)

#ifdef TEST_IMPL_WITH_MAIN
#include "main.c"
#endif
#endif
