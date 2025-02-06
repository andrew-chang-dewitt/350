#include <stdio.h>
void swap(int **p, int **q) {
  int *tmp = *p;

  *p = *q;
  *q = tmp;
}

int main() {
  int a, b, *c = &a, *d = &b;
  printf("before swap:\n&a: %x\n&b: %x\nc: %x\nd: %x\n\n", &a, &b, c, d);

  swap(&c, &d);

  printf("after swap:\n&a: %x\n&b: %x\nc: %x\nd: %x\n\n", &a, &b, c, d);
}
