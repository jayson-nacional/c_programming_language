#include <stdio.h>

int power(int base, int exponent);

int main() {
  for (int i = 0; i < 10; i++) {
    printf("%d %d %d\n", i, power(2, i), power(-2, i));
  }

  return 0;
}

int power(int base, int exponent) {
  int p = 1;
  for (int i = 1; i <= exponent; i++)
    p = p * base;

  return p;
}
