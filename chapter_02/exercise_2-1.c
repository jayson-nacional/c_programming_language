/* Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from the
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types. */

#include <limits.h>
#include <stdio.h>

int power(int base, int exponent);
long lpower(long base, long exponent);

int main() {
  printf("FROM HEADERS\n");
  printf("Char ranges\n");
  printf("Char min: %d\n", CHAR_MIN);
  printf("Char max: %d\n", CHAR_MAX);
  printf("UChar min: %d\n", 0);
  printf("UChar max: %d\n", UCHAR_MAX);

  putchar('\n');
  printf("Short ranges\n");
  printf("Short min: %d\n", SHRT_MIN);
  printf("Short max: %d\n", SHRT_MAX);
  printf("UShort min: %d\n", 0);
  printf("UShort max: %d\n", USHRT_MAX);

  putchar('\n');
  printf("Int ranges\n");
  printf("Int min: %d\n", INT_MIN);
  printf("Int max: %d\n", INT_MAX);
  printf("UInt min: %d\n", 0);
  printf("UInt max: %d\n", UINT_MAX);

  putchar('\n');
  printf("Long ranges\n");
  printf("Long min: %ld\n", LONG_MIN);
  printf("Long max: %ld\n", LONG_MAX);
  printf("ULong min: %d\n", 0);
  printf("ULong max: %lu\n", ULONG_MAX);

  putchar('\n');
  printf("FROM COMPUTATION:\n");
  printf("Signed chars:\n");
  printf("Chars min: %d\n", -power(2, 8) / 2);
  printf("Chars max: %d\n", power(2, 8) / 2 - 1);
  printf("Unsigned chars:\n");
  printf("UChars min: %d\n", 0);
  printf("UChars max: %d\n", power(2, 8) - 1);

  putchar('\n');
  printf("Signed short:\n");
  printf("Short min: %d\n", -power(2, 16) / 2);
  printf("Short max: %d\n", power(2, 16) / 2 - 1);
  printf("Unsigned short:\n");
  printf("UShort min: %d\n", 0);
  printf("UShort max: %d\n", power(2, 16) - 1);

  putchar('\n');
  printf("Signed long:\n");
  printf("Long min: %ld\n", -lpower(2L, 63L));
  printf("Long max: %ld\n", lpower(2L, 63L) - 1);
  printf("Unsigned long:\n");
  printf("ULong min: %d\n", 0);
  printf("ULong max: %lu\n", (lpower(2L, 63L) - 1) * 2 + 1);

  return 0;
}

int power(int base, int exponent) {
  int output = 1;
  for (int i = 1; i <= exponent; i++)
    output = output * base;

  return output;
}

long lpower(long base, long exponent) {
  long output = 1L;
  for (int i = 1; i <= exponent; i++)
    output = output * base;

  return output;
}
