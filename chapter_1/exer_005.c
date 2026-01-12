// Modify the temperature conversion program to print the table in reverse
// order, that is, from 300 degrees to 0

#include <stdio.h>

int main() {
  printf("Fahr\tCelsius\n");
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  for (fahr = upper; fahr >= 0; fahr = fahr - step) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%4.0f %10.1f\n", fahr, celsius);
  }

  return 0;
}
