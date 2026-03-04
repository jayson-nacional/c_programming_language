// In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to -(2
// raised to wordsize-1). Explain why not. Modify it to print that value
// correctly, regardless of the machine on which it runs.
//
// Explanation: The logic to itoa involves performing modulus towards the input
// n, in which case doing this against the largest negative integer value causes
// an overflow. This can be averted by making sure that the variable is capable
// of holding the value which is done by setting the type to long

#include <limits.h>
#include <stdio.h>

void itoa(long n, char s[]);
void reverse(char s[]);

int main() {
  char s[100];
  printf("%d\n", INT_MIN);
  itoa(INT_MIN, s);

  return 0;
}

void itoa(long n, char s[]) {
  int i, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; ++i)
    ;

  while (i >= 0)
    putchar(s[i--]);

  putchar('\n');
}
