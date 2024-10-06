#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  /* table header */
  printf("Fahrenheit\tCelsius\n");

  float fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%10.0f\t%7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }

  return 0;
}
