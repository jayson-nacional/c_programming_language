#include <stdio.h>

#define TABSTOP 4

void print_char(char c, int count);

int main() {
  int c;
  int i = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      print_char('*', TABSTOP - i);
      i = 0;
    } else {
      putchar(c);
      ++i;
    }

    if (i == TABSTOP)
      i = 0; // reset
  }

  return 0;
}

void print_char(char c, int count) {
  while (count-- > 0)
    putchar(c);
}
