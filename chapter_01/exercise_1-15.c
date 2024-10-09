#include <stdio.h>

/* Rewrite the temperature conversion program to use a function for conversion
 */
float convert_to_celsius(int fahrenheit);
float convert_to_fahrenheit(int celsius);

int main() {
  printf("Fahrenheit\tCelsius\n");
  for (int base = 0; base <= 300; base = base + 20)
    printf("%10d\t%7.1f\n", base, convert_to_celsius(base));

  printf("Celsius\tFahrenheit\n");
  for (int base = 0; base <= 100; base = base + 5)
    printf("%7d\t%10.1f\n", base, convert_to_fahrenheit(base));

  return 0;
}

float convert_to_celsius(int fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32);
}

float convert_to_fahrenheit(int celsius) { return (9.0 / 5.0) * celsius + 32; }
