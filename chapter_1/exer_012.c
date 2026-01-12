// Write a program that prints its input one word per line

#include <stdio.h>

int main() {
  int c; /* current char */
  int p; /* previous char */

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (p != ' ' && p != '\t')
        putchar('\n');
    } else
      putchar(c);

    p = c;
  }

  return 0;
}
