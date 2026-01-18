// Write a program to determine the ranges of char, short, int, and long
// variables, both signed and unsigned, by printing appropriate values from
// standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

int main() {
  // by reference
  // char
  printf("--- Char ranges ---\n");
  printf("signed char min: %d\n", CHAR_MIN);
  printf("signed char max: %d\n", CHAR_MAX);
  printf("unsigned char min: 0\n");
  printf("unsigned char max: %d\n", UCHAR_MAX);

  // short
  printf("--- Short ranges ---\n");
  printf("signed short min: %d\n", SHRT_MIN);
  printf("signed short max: %d\n", SHRT_MAX);
  printf("unsigned short min: 0\n");
  printf("unsigned short max: %d\n", USHRT_MAX);

  // int
  printf("--- Int ranges ---\n");
  printf("signed int min: %d\n", INT_MIN);
  printf("signed int max: %d\n", INT_MAX);
  printf("unsigned int min: 0\n");
  printf("unsigned int max: %u\n", UINT_MAX);

  // long
  printf("--- Long ranges ---\n");
  printf("signed long min: %ld\n", LONG_MIN);
  printf("singed long max: %ld\n", LONG_MAX);
  printf("unsigned long min: 0\n");
  printf("unsigned long max: %lu\n", ULONG_MAX);

  // by computation
  // char
  printf("--- Char ranges by computation ---\n");
  printf("signed char min: %.0f\n", -pow(2.0, 7.0));
  printf("signed char max: %.0f\n", pow(2.0, 7.0) - 1);
  printf("unsigned char min: 0\n");
  printf("unsigned char max: %.0f\n", pow(2.0, 8.0) - 1);

  // short
  printf("--- Short ranges by computation ---\n");
  printf("signed short min: %.0f\n", -pow(2.0, 15.0));
  printf("signed short max: %.0f\n", pow(2.0, 15.0) - 1);
  printf("unsigned short min: 0\n");
  printf("unsigned short max: %.0f\n", pow(2.0, 16.0) - 1);

  // int
  printf("--- Int ranges by computation ---\n");
  printf("signed int min: %.0f\n", -pow(2.0, 31.0));
  printf("signed int max: %.0f\n", pow(2.0, 31.0) - 1);
  printf("unsigned int min: 0\n");
  printf("unsigned int max: %.0f\n", pow(2.0, 32.0) - 1);

  // long
  printf("--- Long ranges by computation ---\n");
  printf("signed long min: %.0f\n", -pow(2.0, 63.0));
  printf("signed long max: %.0f\n",
         pow(2.0, 63.0) - 1); /* not accurate as will result to overflow */
  printf("unsigned long min: 0\n");
  printf("unsigned long max: %.0f\n", pow(2.0, 64.0) - 1);

  return 0;
}
