#include <stdio.h>

#include "llist.h"

#ifndef Vec_int
declare_vec(int)
#endif

typedef struct {
  char *name;
} Thing;

void free_thing(Thing *thing) {
  free(thing->name);
}

#ifndef Vec_Thing
declare_vec(Thing)
#endif


int main(int argc, char* argv[argc + 1]) {
  Vec_int int_vec = vec_new(int);

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

  __Node_int *next_int = int_vec._head;
  printf("int_vec: [");
  while(next_int) {
    printf("%d,", next_int->_value);
    next_int = next_int->_next;
  }
  printf("]\n\n");

  Vec_Thing thing_vec = vec_new_with_free(Thing, &free_thing);

  thing_vec.vtable->append(&thing_vec, (Thing){.name="bob"});
  //thing_vec.vtable->append(&thing_vec, (Thing){.name="jon"});

  //thing_vec.vtable->prepend(&thing_vec, (Thing){.name="sue"});

  printf("thing_vec is %d long\n", thing_vec.len);

  __Node_Thing *next_thing = thing_vec._head;
  printf("thing_vec: [");
  while(next_thing) {
    printf("Thing { .name = %s },", next_thing->_value.name);
    next_thing = next_thing->_next;
  }
  printf("]\n\n");


  thing_vec.vtable->destroy(thing_vec);
}
