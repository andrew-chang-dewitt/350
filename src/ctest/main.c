#include "lib.h"

static void exec_test(Test *test, Report *report) {
  TestResult result = test->run();
  if (Result_is_ok(&result)) {
    putchar('.');
    report->pass++;
  } else {
    Failure f = Result_unwrap_err(&result);
    report->failures.vtable->append(&report->failures, f);
  }
}

static int run(Vec_Test *tests, Report *report) {
  if (!tests->len) {
    printf("[ctest] Warning: No tests found\n\n");
    return 0;
  }

  Iterable_Test i = tests->vtable->iter(tests);
  Test *test = i.vtable->next(&i);
  while (test) {
    exec_test(test, report);
    test = i.vtable->next(&i);
  };

  return 0;
}

#define TEST_MAIN                                                              \
  int main(int _, char **__) {                                                 \
    Vec_Test tests = vec_new(Test, NULL);                                      \
    /* TODO: somehow inject test discovery here, likely using a python*/       \
    /*script to crawl a dir & list of files for TEST invocations & then*/      \
    /*concat those into a file that's included at a marker comment*/           \
    /*for now, we'll manually do it by including the test files directly*/     \
    Vec_Failure failures = vec_new(Failure, NULL);                             \
    Report report = {.pass = 0, .failures = &failures};                        \
    printf("\n\n[ctest] Running tests...\n\n");                                \
    int exit = run(&tests, &report);                                           \
    printf("[ctest] Done.\n");                                                 \
    return exit;                                                               \
  }

#ifndef TEST_MAIN_DECLARED
#define TEST_MAIN_DECLARED
TEST_MAIN
#endif
