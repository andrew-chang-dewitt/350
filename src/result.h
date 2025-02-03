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

