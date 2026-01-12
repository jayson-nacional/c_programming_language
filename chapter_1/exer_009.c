// Write a program to copy copy its input to its output, replacing each string
// of one or more blanks by a single blank

#include <stdio.h>

int main() {
  int c; /* current char */
  int p; /* previous char */

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (p != ' ' && p != '\t')
        putchar(' ');
    } else {
      putchar(c);
    }

    p = c;
  }

  return 0;
}
