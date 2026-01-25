// function get_bits(x, p, n) returns the (right adjusted) n-bit field of x that
// begins at position p. We assume that bit position 0 is at the right end and
// that n and p are sensible positive values. For example, getbits(x, 4, 3)
// returns three bits in positions 4, 3, and 2 right-adjusted.

#include <stdio.h>

unsigned get_bits(unsigned x, int p, int n);

int main() {
  int test = 4;
  printf("%d\n", get_bits(127, 4, 3));
  return 0;
}

unsigned get_bits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}
