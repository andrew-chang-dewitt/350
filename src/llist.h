#include <stdlib.h>

#define __Node(T)\
  typedef struct __Node_##T {\
    struct __Node_##T *_prev;\
    struct __Node_##T *_next;\
    T _value;\
  } __Node_##T;

#define __Vec(T)\
  typedef struct {\
    __Node_##T *_head;\
    __Node_##T *_tail;\
    void (*_free)(T *);\
    const struct __Vec_##T##_vtable *vtable;\
    int len;\
  } Vec_##T;

#define __vec_destroy(T)\
  void __vec_##T##_destroy(Vec_##T vec) {\
    __Node_##T *current;\
    while(vec._tail) {\
      current = vec._tail;\
      vec._tail = vec._tail->_prev;\
      if (vec._free) {\
        vec._free(current->_value);\
      }\
      free(current);\
    }\
    free(vec._head);\
  }

#define __vec_append(T)\
  void __vec_##T##_append(Vec_##T *vec, T value) {\
    __Node_##T *node = malloc(sizeof(__Node_##T));\
    node->_value = value;\
    if (vec->len == 0) {\
      vec->_head = node;\
    } else {\
      vec->_tail->_next = node;\
    }\
    vec->_tail = node;\
    vec->len++;\
  }

#define __vec_prepend(T)\
  void __vec_##T##_prepend(Vec_##T *vec, T value) {\
    __Node_##T *node = malloc(sizeof(__Node_##T));\
    node->_value = value;\
    if (vec->len == 0) {\
      vec->_tail = node;\
    } else {\
      vec->_head->_prev = node;\
    }\
    vec->_head = node;\
    vec->len++;\
  }

#define __Vec_declare_Vtable(T)\
  struct __Vec_##T##_vtable {\
    void (*destroy)(Vec_##T vec);\
    void (*append)(Vec_##T *vec, T value);\
    void (*prepend)(Vec_##T *vec, T value);\
    /*void (*for_each)(Vec_##T vec, void (*fn)(T value));*/\
    /*char* (*display)(Vec_##T vec);*/\
  };\
  struct __Vec_##T##_vtable __vec_##T##_vtable = {\
    .destroy = __vec_##T##_destroy,\
    .append = __vec_##T##_append,\
    .prepend = __vec_##T##_prepend\
    /*.for_each = __vec_##T##_for_each*/\
    /*.display = __vec_##T##_display*/\
  };

#define declare_vec(T)\
  __Node(T)\
  __Vec(T)\
  __vec_destroy(T)\
  __vec_append(T)\
  __vec_prepend(T)\
  __Vec_declare_Vtable(T)\
  /* TODO: */\
  /*__vec_for_each(T)*/\
  /*__vec_reduce(T,U)*/\
  /*__vec_display(T)*/\
  /*__vec_map(T,U)*/

#define vec_new(T) \
  {\
    ._head = 0,\
    ._tail = 0,\
    ._free = 0,\
    .vtable = &__vec_##T##_vtable,\
    .len = 0\
  }

#define vec_new_with_free(T, freeFn) \
  {\
    ._head = 0,\
    ._tail = 0,\
    ._free = freeFn,\
    .vtable = &__vec_##T##_vtable,\
    .len = 0\
  }
