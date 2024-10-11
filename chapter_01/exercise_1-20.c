#include <stdio.h>

/* Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter? */
#define MAXLINE 1000
#define TAB_STOP 4

int get_line(char line[], int limit);
void detab(char line[]);
void print_spaces(int count);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    detab(line);
  }

  return 0;
}

int get_line(char line[], int limit) {
  int i, c;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void detab(char line[]) {
  int i = 0;
  int column_index = 0;
  int spaces;

  while (line[i] != '\0') {
    if (line[i] == '\t') {
      spaces = TAB_STOP - column_index;

      if (spaces == 0)
        print_spaces(TAB_STOP);
      else
        print_spaces(spaces);

      column_index = 0;
    } else {
      putchar(line[i]);
      ++column_index;

      if (column_index == TAB_STOP)
        column_index = 0;
    }

    ++i;
  }
}

void print_spaces(int count) {
  for (--count; count >= 0; count--)
    putchar(' ');
}
