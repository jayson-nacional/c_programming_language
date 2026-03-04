// In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to -(2
// raised to wordsize-1). Explain why not. Modify it to print that value
// correctly, regardless of the machine on which it runs.

#include <limits.h>
#include <stdio.h>

void itoa(int n, char s[]);
void itoa2(int n, double s[]);

int main() {
  double s[100];
  printf("%d\n", INT_MIN);
  itoa2(INT_MIN, s);

  int i = 0;
  while (s[i] != '\0') {
    putchar(s[i]);
    i++;
  }

  return 0;
}

void itoa(int n, char s[]) {
  int i;
  double sign;
  double newn;

  newn = n;
  if ((sign = newn) < 0) {
    printf("Was called\n");
    newn = -newn;
  }

  i = 0;
  do {
    printf("Loop was called 1\n");
    s[i++] = (newn & 1) + '0';
    printf("Loop was called 2\n");
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
}

void itoa2(int n, double s[]) {
  int i;
  int sign;

  if ((sign = n) < 0) {
    printf("Was called\n");
    n = -n;
  }

  i = 0;
  do {
    printf("Loop was called 1\n");
    s[i++] = (n & 1) + '0';
    printf("Loop was called 2\n");
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
}
