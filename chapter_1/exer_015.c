// Rewrite the temperature conversion program of Section 1.2 to use a function
// for conversion
#include <stdio.h>

float convert_to_celsius(float fahr);

int main() {
  printf("Fahr\tCelsius\n");
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    printf("%4.0f %10.1f\n", fahr, convert_to_celsius(fahr));
    fahr = fahr + step;
  }

  return 0;
}

float convert_to_celsius(float fahr) { return (5.0 / 9.0) * (fahr - 32); }
