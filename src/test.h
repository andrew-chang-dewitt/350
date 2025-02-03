#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// from https://gist.github.com/f0rki/9b2c2b73d46ccdad2b39ab79b3a5517f
#define DEFINE_RESULT(T, E, NAME)\
typedef struct {\
  int success : 1;\
  union {\
    T result;\
    E error;\
  };\
} NAME; \
int Result_is_ok(NAME *r) {\
  return r->success;\
}\
T Result_unwrap(NAME *r) {\
  if (r->success) {\
    return r->result;\
  } else {\
    panicf("Attempted to unwrap Result<#T,#E>, but it contained an Err(%s)", r->error);\
  }\
}\
E Result_unwrap_err(NAME *r) {\
  if (!r->success) {\
    return r->error;\
  } else {\
    panicf("Attempted to unwrap error on Result<#T,#E>, but it contained an Ok()", r->result);\
  }\
}

// from https://codereview.stackexchange.com/q/140231
void panicf(const char *fmt, ...) __attribute__((noreturn));
void panicf(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vfprintf(stderr, fmt, args);

    exit(1);
}

typedef struct Empty {} Empty;

struct Failure {
  char *test;
  char *assertion;
  char *file;
  int line;
};


DEFINE_RESULT(Empty, struct Failure, TestResult)

struct Node {
  struct Node *next;
  struct Node *prev;
  TestResult (*exec)();
  char *file;
  char *name;
};

struct List {
  struct Node *head;
  struct Node *tail;
  int size;
  char *name;

  // TODO:
  // void (*before)();
  // void (*after)();
  // void (*beforeEach)();
  // void (*afterEach)();
};

static void _list_append(struct List *list, struct Node *node) {
  if (!list->head) {
    list->head = node;
  }

  struct Node *prev_tail = list->tail;
  node->prev = prev_tail;
  node->next = NULL;
  list->tail = node;
  list->size++;
}

struct Iterable {
  struct Node *next;
};

static struct Iterable _list_iter(struct List *list) {
  return (struct Iterable){.next = list->head};
}

static struct Node *_iterable_next(struct Iterable *iter) {
  struct Node *out = iter->next;
  iter->next = out->next;

  return out;
}

static int _iterable_has_next(struct Iterable *iter) {
  if (!iter->next) {
    return 0;
  } else {
    return 1;
  }
}

struct List root = {.head = NULL, .tail = NULL, .size = 0};

struct Report {
  int pass;
  struct Failure failures[];
};

struct Report report = {.pass=0};

static void exec_test(struct Node *test, struct Report *report) {
  TestResult result = test->exec();
  if (Result_is_ok(&result)) {
    putchar('.');
    report->pass++;
  } else {
    struct Failure f = Result_unwrap_err(&result);
    report->failures[0] = f;
  }
}

static int run(struct List *tests, struct Report *report) {
  if (!tests->size) {
    printf("No tests found.\n\n");
    return 0;
  }

  struct Iterable i = _list_iter(tests);
  while (_iterable_has_next(&i)) {
    exec_test(_iterable_next(&i), report);
  }

  // putchar('\n');
  return 0;
}

#define TEST_MAIN                                                              \
  int main(int _, char **__) {                                                 \
    printf("\n\n[test.h] Running tests...\n\n");                               \
    int exit = run(&root, &report);                                            \
    printf("Done.\n");                                                         \
    return exit;                                                               \
  }

#ifdef TEST_IMPL_WITH_MAIN
TEST_MAIN
#endif

// TODO: define these now so that tests will get registered & their bodies will be called by Node->exec()

// replace test w/ function that registers test onto an object
// struct Node {
//   struct Node *next;
//   struct Node *prev;
//   TestResult (*exec)();
//   char *file;
//   char *name;
// };
#define TEST(name, fn)                                                         \
  _list_append(&root, {                                                        \
    .name=name,                                                                \
    .exec=fn,                                                                  \
    .file=__FILE__,                                                            \
  })

#define ASSERT(ast) \
  // TODO: need to somehow give an id to this function? not sure what to do...
//   do { \
//     assertion = #ast; \
//     file = __FILE__; \
//     line = __LINE__; \
//     if (ast) { \
//       putchar('.'); \
//     } else { \
//       putchar('F'); \
//     } \
//   } while (0)
