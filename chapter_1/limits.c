#include <float.h>
#include <limits.h>
#include <stdio.h>

int power_base_2(int n);
unsigned long ul_power_base_2(int n);
long l_power_base_2(int n);
float f_power_base_2(int n);
double d_power_base_2(int n);

int main() {
  // char header based
  printf("Signed char min: %d\n", CHAR_MIN);
  printf("Signed char max: %d\n", CHAR_MAX);
  printf("Unsigned char min: %d\n", 0);
  printf("Unsigned char max: %d\n", UCHAR_MAX);

  // char compute based
  printf("Signed char min: %d\n", -(power_base_2(7))); // 8 bits - 1
  printf("Signed char max: %d\n", power_base_2(7) - 1);
  printf("Unsigned char min: %d\n", 0);
  printf("Unsigned char max: %d\n", power_base_2(8) - 1);

  // short compute header based
  printf("Signed short min: %hi\n", SHRT_MIN);
  printf("Signed short max: %hi\n", SHRT_MAX);
  printf("Unsigned short min: %hu\n", 0);
  printf("Unsigned short max: %hu\n", USHRT_MAX);

  // short compute based based
  printf("Signed short min: %hi\n", -(power_base_2(15))); // 16 bits - 1
  printf("Signed short max: %hi\n", power_base_2(15) - 1);
  printf("Unsigned short min: %hu\n", 0);
  printf("Unsigned short max: %hu\n", power_base_2(16) - 1);

  // int header based
  printf("Signed int min: %d\n", INT_MIN);
  printf("Signed int max: %d\n", INT_MAX);
  printf("Unsigned int min: %d\n", 0);
  printf("Unsigned int max: %u\n", UINT_MAX);

  // int compute based
  printf("Signed int min: %d\n", -(power_base_2(31))); // 32 bits - 1
  printf("Signed int max: %d\n", power_base_2(31) - 1);
  printf("Unsigned int min: %d\n", 0);
  printf("Unsigned int max: %u\n", power_base_2(32) - 1);

  // long header based
  printf("Signed long min: %ld\n", LONG_MIN);
  printf("Signed long max: %ld\n", LONG_MAX);
  printf("Unsigned long min: %ld\n", 0L);
  printf("Unsigned long max: %lu\n", ULONG_MAX);

  // long compute based
  printf("Signed long min: %ld\n", -(l_power_base_2(63))); // 64 bits - 1
  printf("Signed long max: %ld\n", l_power_base_2(63) - 1);
  printf("Unsigned long min: %ld\n", 0L);
  printf("Unsigned long max: %lu\n", ul_power_base_2(64) - 1);

  // float header based
  printf("Float min: %f\n", FLT_MIN);
  printf("Float max: %f\n", FLT_MAX);

  // float compute based
  printf("Float min: %f\n", 0.000000);
  printf("Float max: %lf\n", d_power_base_2(128) - 1); // TODO: validate

  // double header based
  printf("Double min: %f\n", DBL_MIN);
  printf("Double max: %f\n", DBL_MAX);

  // double compute based
  printf("Double min: %f\n", 0.000000);
  printf("Double max: %lf\n", d_power_base_2(1023) - 1); // TODO: validate

  return 0;
}

int power_base_2(int n) {
  int result = 1;

  while (n-- > 0) {
    result = result * 2;
  }

  return result;
}

unsigned long ul_power_base_2(int n) {
  unsigned long result = 1;

  while (n-- > 0) {
    result = result * 2;
  }

  return result;
}

long l_power_base_2(int n) {
  long result = 1;

  while (n-- > 0) {
    result = result * 2;
  }

  return result;
}

float f_power_base_2(int n) {
  float result = 1;

  while (n-- > 0) {
    result = result * 2;
  }

  return result;
}

double d_power_base_2(int n) {
  double result = 1;

  while (n-- > 0) {
    result = result * 2;
  }

  return result;
}
