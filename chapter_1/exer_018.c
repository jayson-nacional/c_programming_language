// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
  int len;
  char line[MAXLINE];

  len = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    printf("%s", line);
  }
}

int get_line(char s[], int lim) {
  int c, i;
  int p; /* previous character */

  i = 0;
  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
    if (c == ' ' || c == '\t') {
      if (p != ' ' && p != '\t') {
        s[i] = c;
        ++i;
      }
    } else {
      s[i] = c;
      ++i;
    }

    p = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}
