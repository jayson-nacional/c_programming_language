#include <stdio.h>

/* Modify the temperature conversion program to print the table in reverse
 * order, from 300 degrees to 0 */
int main() {
  /* table header */
  printf("Fahrenheit\tCelsius\n");

  for (float fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%10.0f\t%7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
  return 0;
}
