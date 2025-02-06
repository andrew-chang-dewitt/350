#include "../macros/concat.c"
#include "../macros/defer.c"
#include "../macros/echo.c"
#include "../macros/for_each.c"

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

#define _create_test_fn(num, desc)                                             \
  char *ECHO(CONCAT(_desc_test, num)) = desc;                                  \
  TestResult ECHO(CONCAT(_fn_test, num))()

#define _

#define TEST(desc, body) _create_test_fn(__COUNTER__, desc)

#ifdef TEST_IMPL_WITH_MAIN
#define SUITE(desc, ...)                                                       \
  /*create test functions from args*/                                          \
  FOR_EACH(ECHO, __VA_ARGS__)                                                  \
  /*test main fn that runs given test functions*/                              \
  int main(int _, char **__) {                                                 \
    Vec_Test tests = vec_new(Test, NULL);                                      \
    /*                                                                         \
    FOR_EACH(_append_test_to_vec, __VA_ARGS__)                                 \
     */                                                                        \
    Report report = {.pass = 0, .failures = vec_new(Failure, NULL)};           \
    printf("\n\n[ctest] Running tests...\n\n");                                \
    int exit = run(&tests, &report);                                           \
    printf("[ctest] Done.\n");                                                 \
    tests.vtable->destroy(tests);                                              \
    report.failures.vtable->destroy(report.failures);                          \
    return exit;                                                               \
  }
#endif
