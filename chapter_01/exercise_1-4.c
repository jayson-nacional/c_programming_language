#include <stdio.h>

/* Write a program to print the corresponding Celsius to Fahrenheit table */

int main() {
  float celsius, fahr;
  float upper, lower, step;

  lower = 0;   /* lower celsius limit */
  upper = 100; /* upper celsius limit */
  step = 5;    /* step size */

  /* table header */
  printf("Celsius\tFahrenheit\n");
  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%7.0f\t%10.0f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
