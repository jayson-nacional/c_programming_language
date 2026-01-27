// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
// in x. Explain why. Use this observation to write a faster version of bitcount
//
// Explanation: In a binary system, subtracting a number by 1 would locate the
// first occurence of 1 bit and toggle it to 0. If the rightmost bit is 1 then
// it becomes 0, however if it is at position 1 and above then it toggles that
// bit to 0 then the other bits to the right becomes 1. Now that we make an &
// operator to its previous value where initially all values to the right of the
// current bit is 0 then we always get the 0 bits to the right. Doing a loop
// using this until the number becomes 0 then help us count the number of 1s in
// the given binary

#include <stdio.h>

int bitcount(unsigned int x);

int main() {
  printf("Bitcount of 369 is: %d\n", bitcount(369));

  return 0;
}

int bitcount(unsigned int x) {
  int i;

  for (i = 0; x != 0; x &= (x - 1))
    i++;

  return i;
}
