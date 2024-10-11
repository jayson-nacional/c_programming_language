#include <stdio.h>

/* Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * detab. When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference? */

#define MAXLINE 1000
#define TAB_STOP 4

int get_line(char line[], int limit);
void entab(char line[]);
void print_spaces(int count);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    entab(line);
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

void entab(char line[]) {
  int i = 0;
  int column_index = 0;
  int spaces = 0;
  int p; /* previous */

  while (line[i] != '\0') {
    if (line[i] == ' ' || line[i] == '\t') {
      if (p != ' ' && p != '\t') {
        spaces = TAB_STOP - column_index;
        print_spaces(spaces);
        column_index = 0;
      }
    } else {
      ++column_index;
      putchar(line[i]);

      if (column_index == TAB_STOP)
        column_index = 0;
    }

    p = line[i];
    i++;
  }
}

void print_spaces(int count) {
  for (--count; count >= 0; count--)
    putchar('*');
}
