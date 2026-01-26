// Write a function invert(x, p, n) that returns x with the n bits that begin at
// position p inverted (i.e, 1 changed to 0 and vice versa), leaving the others
// unchanged.

#include <stdio.h>

int invert(int x, unsigned int p, unsigned int n);

int main() {
  printf("Invert: %d\n", invert(369, 5, 3));
  return 0;
}

int invert(int x, unsigned int p, unsigned int n) {
  int mask = ~(~0 << (p - n + 1)) << (p - n + 1);
  return x ^ mask;
}
