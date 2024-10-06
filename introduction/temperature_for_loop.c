#include <stdio.h>

int main() {
  /* Fahrenheit - Celsius Table using for loop */
  printf("Fahrenheit\tCelsius\n");

  for (float fahr = 0; fahr <= 300; fahr = fahr + 20) {
    printf("%10.0f\t%7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }

  return 0;
}
