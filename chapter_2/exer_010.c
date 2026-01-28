// Rewrite the function lower, which converts upper case letters to lower case,
// with conditional expression instead of if-else.

#include <stdio.h>

char lower(char s);

int main() {
  printf("Lower case of P is %c\n", lower('P'));
  return 0;
}

char lower(char s) { return (s >= 'A' && s <= 'Z') ? (s + 'a' - 'A') : s; }
