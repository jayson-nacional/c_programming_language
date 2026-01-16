// Write a program detab that replaces tabs in its input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
// every n columns. Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define TAB_STOP 4
#define MAXLINE 1000

void detab(char s[]);
int get_line(char s[], int lim);

int main() {
  int len;
  char line[MAXLINE];
  while ((len = get_line(line, MAXLINE)) > 0) {
    detab(line);
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void detab(char s[]) {
  int i, j, current_column;

  i = current_column = 0;
  while (s[i] != '\0') {
    if (s[i] == '\t') {
      for (j = current_column; j < TAB_STOP; ++j)
        putchar(' ');
      current_column = 0;
    } else {
      putchar(s[i]);
      ++current_column;
    }

    if (current_column == TAB_STOP) /* reset the column once reached */
      current_column = 0;

    ++i;
  }
}
