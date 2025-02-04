#include <stdio.h>

#include "llist.c"

#ifndef Vec_int
declare_vec(int)
#endif

    void print_int(int *i) {
  printf("%d, ", *i);
}

typedef struct {
  char *name;
} Thing;

#ifndef Vec_Thing
declare_vec(Thing)
#endif

    void print_thing(Thing *t) {
  printf("Thing {.name = %s}, ", t->name);
}

int main(int argc, char *argv[argc + 1]) {
  Vec_int int_vec = vec_new(int, NULL);

  int_vec.vtable->append(&int_vec, 0);
  int_vec.vtable->append(&int_vec, 1);
  int_vec.vtable->append(&int_vec, 2);
  int_vec.vtable->append(&int_vec, 3);
  int_vec.vtable->append(&int_vec, 4);
  int_vec.vtable->append(&int_vec, 5);
  int_vec.vtable->append(&int_vec, 6);
  int_vec.vtable->append(&int_vec, 7);
  int_vec.vtable->append(&int_vec, 8);
  int_vec.vtable->append(&int_vec, 9);

  printf("int_vec is %d long\n", int_vec.len);

  printf("int_vec: [");

  Iterable_int int_iter = int_vec.vtable->iter(&int_vec);
  int_iter.vtable->for_each(&int_iter, &print_int);

  printf("]\n\n");

  Vec_Thing thing_vec = vec_new(Thing, NULL);

  thing_vec.vtable->append(&thing_vec, (Thing){.name = "bob"});
  thing_vec.vtable->append(&thing_vec, (Thing){.name = "jon"});

  thing_vec.vtable->prepend(&thing_vec, (Thing){.name = "sue"});

  printf("thing_vec is %d long\n", thing_vec.len);

  printf("thing_vec: [");

  Iterable_Thing thing_iter = thing_vec.vtable->iter(&thing_vec);
  thing_iter.vtable->for_each(&thing_iter, &print_thing);

  printf("]\n\n");

  thing_vec.vtable->destroy(thing_vec);

  printf("done.\n\n\n");
}
