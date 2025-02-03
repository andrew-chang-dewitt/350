#include <stdio.h>

struct thing {
  char *name;
  struct thing *next;
  void (*fn)();
};

struct thing new_thing(char *name, void (*fn)()) {
  return (struct thing){.name = name, .fn = fn, .next = 0};
}

struct thing *head = 0;
struct thing *tail = 0;

void add_thing(struct thing *new) {
  if (!head) {
    head = new;
    tail = new;
  }
  tail->next = new;
  tail = new;
}

// FIXME: the below doesn't work because the function calls must happen inside
// another function. To resolve this, I need to look at something closer to how
// [this example][1] includes the macro calls inside a test main
// - [1]: https://www.reddit.com/r/C_Programming/comments/vfm3s7/comment/icwsoac
// #define reg(name, body) \
//   char *n = #name; \
//   void name##_fn() body struct thing name = new_thing(#name, &name##_fn); \
//   add_thing(*name);
//
// #define printname() printf("%s", n);
//
// reg(first, {printname()})
// char *n = "first";
// void first_fn() { printf("%s", n); }
// struct thing first = {.name = "first", .next = 0, .fn = &first_fn};
// maybe there's something in the idea of each test is prepended to the llist,
// updating the head each time?

int main(int argc, [[maybe_unused]] char *argv[argc - 1]) {
  printf("Beginning...\n\n");
  struct thing *next = head;

  while (next) {
    next->fn();
    next = next->next;
  }

  printf("\n...Ending");
  return 0;
}
