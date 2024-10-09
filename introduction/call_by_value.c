#include <stdio.h>

int power(int base, int exponent);

int main() {
  for (int i = 0; i < 10; i++)
    printf("%d %d %d\n", i, power(2, i), power(-2, i));

  return 0;
}

int power(int base, int exponent) {
  int p = 1;

  for (; exponent; --exponent)
    p = p * base;

  return p;
}
