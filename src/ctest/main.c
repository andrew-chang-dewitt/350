#ifdef TEST_IMPL_WITH_MAIN
#include "lib.h"

#define TEST_MAIN                                                              \
  int main(int _, char **__) {                                                 \
    Vec_Test tests = vec_new(Test, NULL);                                      \
    printf("\n\n[ctest] Running tests...\n\n");                                \
    /*int exit = run(&tests, &report);*/                                       \
    int exit = run(&tests);                                                    \
    printf("[ctest] Done.\n");                                                 \
    return exit;                                                               \
  }

// static void exec_test(struct Node *test, struct Report *report) {
static void exec_test(Test *test) {
  TestResult result = test->run();
  if (Result_is_ok(&result)) {
    putchar('.');
    // report->pass++;
  } /*else {
    Failure f = Result_unwrap_err(&result);
    // report->failures[0] = f;
  }*/
}

// static int run(struct List *tests, struct Report *report) {
static int run(Vec_Test *tests) {
  if (!tests->len) {
    printf("[ctest] Warning: No tests found\n\n");
    return 0;
  }

  Iterable_Test i = tests->vtable->iter(tests);
  Test *test = i.vtable->next(&i);
  while (test) {
    // exec_test(test, report);
    exec_test(test);
    test = i.vtable->next(&i);
  };

  // putchar('\n');
  return 0;
}

TEST_MAIN
#endif
