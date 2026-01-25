// Write a function setbits(x, p, n, y) that returns x with the n bits that
// begin at position p set to the rightmost n bits of y, leaving other bits
// unchanged.

#include <stdio.h>

int setbits(int x, unsigned int p, unsigned int n, int y);

int main() {
  printf("setbits test: %d\n", setbits(369, 5, 3, 7));
  return 0;
}

int setbits(int x, unsigned int p, unsigned int n, int y) {
  // create a mask first to convert p to n into zero
  int first_mask = ~0 << (p + 1) | ~(~0 << (p + 1 - n));

  // create a mask for y to only pick the last n bits and align it to bits of x
  int second_mask = (~(~0 << n) & y) << (p + 1 - n);

  return (x & first_mask) | second_mask;
}
