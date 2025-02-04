#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "test.h"

// declare_vec(Failure);
//
// struct Report {
//   int pass;
//   struct Vec_Failure failures;
// };

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
