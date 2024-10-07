#include <stdio.h>

/* Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank */
int main() {
  int c, p; /* c = current character, p = previous character */
  while ((c = getchar()) != EOF) {
    if (c != ' ' || (c == ' ' && p != ' '))
      putchar(c);

    p = c;
  }

  return 0;
}
