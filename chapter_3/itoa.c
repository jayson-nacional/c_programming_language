#include <limits.h>
#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
  char s[100];
  printf("%d\n", 369);
  itoa(369, s);

  return 0;
}

void itoa(int n, char s[]) {
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
