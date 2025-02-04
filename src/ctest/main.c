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

// TODO: playing with having the SUITE macro expand to a main fn that builds
// the `tests` vec in place from the Test objs created by each TEST macro
// thinking it could be done by having SUITE iterate over __VA_ARGS__,
// declaring a function for the BODY given to each TEST & creating a Test
// object that receives a pointer to that function, then appending that Test
// object to the `tests` vec each time.
#ifdef TEST_IMPL_WITH_MAIN
/*
#define SUITE(name, ...)                                                       \
 */
#define SUITE(name)                                                            \
  int main(int _, char **__) {                                                 \
    Vec_Test tests = vec_new(Test, NULL);                                      \
    Report report = {.pass = 0, .failures = vec_new(Failure, NULL)};           \
    printf("\n\n[ctest] Running tests...\n\n");                                \
    int exit = run(&tests, &report);                                           \
    printf("[ctest] Done.\n");                                                 \
    tests.vtable->destroy(tests);                                              \
    report.failures.vtable->destroy(report.failures);                          \
    return exit;                                                               \
  }
#endif
