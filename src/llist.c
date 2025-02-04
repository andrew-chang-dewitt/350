#include <stdlib.h>

#define __Node(T)                                                              \
  typedef struct __Node_##T {                                                  \
    struct __Node_##T *_prev;                                                  \
    struct __Node_##T *_next;                                                  \
    T _value;                                                                  \
  } __Node_##T;

#define __Vec(T)                                                               \
  typedef struct {                                                             \
    __Node_##T *_head;                                                         \
    __Node_##T *_tail;                                                         \
    void (*_free)(T *);                                                        \
    const struct __Vec_##T##_vtable *vtable;                                   \
    int len;                                                                   \
  } Vec_##T;

#define __vec_destroy(T)                                                       \
  void __vec_##T##_destroy(Vec_##T vec) {                                      \
    __Node_##T *current;                                                       \
    while (vec._tail) {                                                        \
      current = vec._tail;                                                     \
      vec._tail = vec._tail->_prev;                                            \
      if (vec._free) {                                                         \
        vec._free(&current->_value);                                           \
      }                                                                        \
      free(current);                                                           \
    }                                                                          \
  }

#define __vec_append(T)                                                        \
  void __vec_##T##_append(Vec_##T *vec, T value) {                             \
    __Node_##T *node = malloc(sizeof(__Node_##T));                             \
    node->_value = value;                                                      \
    if (vec->len == 0) {                                                       \
      vec->_head = node;                                                       \
    } else {                                                                   \
      vec->_tail->_next = node;                                                \
      node->_prev = vec->_tail;                                                \
    }                                                                          \
    vec->_tail = node;                                                         \
    vec->len++;                                                                \
  }

#define __vec_prepend(T)                                                       \
  void __vec_##T##_prepend(Vec_##T *vec, T value) {                            \
    __Node_##T *node = malloc(sizeof(__Node_##T));                             \
    node->_value = value;                                                      \
    node->_next = vec->_head;                                                  \
    if (vec->len == 0) {                                                       \
      vec->_tail = node;                                                       \
    } else {                                                                   \
      vec->_head->_prev = node;                                                \
      node->_next = vec->_head;                                                \
    }                                                                          \
    vec->_head = node;                                                         \
    vec->len++;                                                                \
  }

#define Iterable(T)                                                            \
  typedef struct {                                                             \
    __Node_##T *_next;                                                         \
    const struct __Iterable_##T##_vtable *vtable;                              \
  } Iterable_##T;

#define __iterable_next(T)                                                     \
  T *__iterable_##T##_next(Iterable_##T *iter) {                               \
    __Node_##T *current = iter->_next;                                         \
    if (current == NULL) {                                                     \
      return NULL;                                                             \
    }                                                                          \
    iter->_next = current->_next;                                              \
    return &current->_value;                                                   \
  }

#define __iterable_for_each(T)                                                 \
  void __iterable_##T##_for_each(Iterable_##T *iter, void (*fn)(T *)) {        \
    T *current = __iterable_##T##_next(iter);                                  \
    while (current != NULL) {                                                  \
      fn(current);                                                             \
      current = __iterable_##T##_next(iter);                                   \
    };                                                                         \
  }

#define __Iterable_declare_vtable(T)                                           \
  struct __Iterable_##T##_vtable {                                             \
    T *(*next)(Iterable_##T *);                                                \
    void (*for_each)(Iterable_##T *, void (*fn)(T *));                         \
  };                                                                           \
  struct __Iterable_##T##_vtable __iterable_##T##_vtable = {                   \
      .next = &__iterable_##T##_next, .for_each = &__iterable_##T##_for_each};

#define __vec_iter(T)                                                          \
  Iterable_##T __vec_iter_##T(Vec_##T *vec) {                                  \
    return (Iterable_##T){                                                     \
        ._next = vec->_head,                                                   \
        .vtable = &__iterable_##T##_vtable,                                    \
    };                                                                         \
  }

#define __Vec_declare_vtable(T)                                                \
  struct __Vec_##T##_vtable {                                                  \
    void (*destroy)(Vec_##T);                                                  \
    void (*append)(Vec_##T *, T);                                              \
    void (*prepend)(Vec_##T *, T);                                             \
    Iterable_##T (*iter)(Vec_##T *);                                           \
    /*char* (*display)(Vec_##T);*/                                             \
  };                                                                           \
  struct __Vec_##T##_vtable __vec_##T##_vtable = {                             \
      .destroy = __vec_##T##_destroy,                                          \
      .append = __vec_##T##_append,                                            \
      .prepend = __vec_##T##_prepend,                                          \
      .iter = __vec_iter_##T};
/*.display = __vec_##T##_display\*/

#define declare_vec(T)                                                         \
  __Node(T) __Vec(T) __vec_destroy(T) __vec_append(T) __vec_prepend(T)         \
      Iterable(T) __iterable_next(T) __iterable_for_each(T)                    \
          __Iterable_declare_vtable(T) __vec_iter(T) __Vec_declare_vtable(T)

/* TODO:*/
/*__vec_reduce(T,U)\*/
/*__vec_display(T)\*/
/*__vec_map(T,U)*/

#define vec_new(T, freeFn)                                                     \
  {._head = NULL,                                                              \
   ._tail = NULL,                                                              \
   ._free = freeFn,                                                            \
   .vtable = &__vec_##T##_vtable,                                              \
   .len = 0}
