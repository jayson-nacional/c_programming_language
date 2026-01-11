// Write a program to print the corresponding Celsius to Fahrenheit table

#include <stdio.h>

int main() {
  printf("Celsius\tFahr\n");
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32;
    printf("%7.0f %4.0f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
