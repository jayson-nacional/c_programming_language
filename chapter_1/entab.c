#include <stdio.h>

#define TABSTOP 4

void print_char(char c, int count);
void minify_spaces(int space_count);

int main() {
  int c, p; // where c = current, p = previous char

  int space_count = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++space_count;
    } else {
      if (p == ' ') {
        minify_spaces(space_count);
        space_count = 0;
      }

      putchar(c);
    }

    p = c;
  }

  return 0;
}

void print_char(char c, int count) {
  while (count-- > 0)
    putchar(c);
}

void minify_spaces(int space_count) {
  while (space_count >= TABSTOP) {
    print_char('*', TABSTOP);
    space_count = space_count - 4;
  }

  print_char('_', space_count);
}
