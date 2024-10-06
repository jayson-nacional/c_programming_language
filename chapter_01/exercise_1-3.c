#include <stdio.h>

/*
 * Modify the temperature conversion program to print a heading above the table
 */

/* Print Fahrenheit-Celsius table
 * for fahr = 0, 20, 40,..., 300 */
int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;   /* lower limit of temperature scale */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  /* Heading */
  printf("Fahrenheit\tCelsius\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%10.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}