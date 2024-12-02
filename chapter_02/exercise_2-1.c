/* Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from the
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types. */

#include <limits.h>
#include <stdio.h>

int main() {
  printf("Char ranges\n");
  printf("Char min: %d\n", CHAR_MIN);
  printf("Char max: %d\n", CHAR_MAX);
  printf("UChar min: %d\n", 0);
  printf("UChar max: %d\n", UCHAR_MAX);

  printf("Short ranges\n");
  printf("Short min: %d\n", SHRT_MIN);
  printf("Short max: %d\n", SHRT_MAX);
  printf("UShort min: %d\n", 0);
  printf("UShort max: %d\n", USHRT_MAX);

  return 0;
}
