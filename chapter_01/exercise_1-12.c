#include <stdio.h>

/* Write a program that prints its input one word per line */
int main() {
  int c, p;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n')
      putchar(c);
    else if (p != ' ' && p != '\t' && p != '\n')
      putchar('\n');

    p = c;
  }

  return 0;
}
