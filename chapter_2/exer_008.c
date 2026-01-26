// Write a function rightrot(x, n) that returns the value of the integer x
// rotated to the right by n positions

#include <stdio.h>

int rightrot(unsigned int x, unsigned int n);

int main() {
  printf("Right rot: %d\n", rightrot(369, 4));

  return 0;
}

int rightrot(unsigned int x, unsigned int n) {
  for (; n > 0; n--) {
    if (x & 1) /* rightmost bit is 1 */
      x = (x >> 1) | ~(~0U >> 1);
    else /* rightmost bit is 0 */
      x = x >> 1;
  }

  return x;
}
