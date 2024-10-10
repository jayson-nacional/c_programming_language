#include <stdio.h>

/* Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines */

#define MAXLINE 1000

int get_line(char line[], int limit);
void trim_line(char line[], int length);
void test_print(char line[], int length); /* test the trimmed line */

int main() {
  int len;            /* length of current line */
  char line[MAXLINE]; /* store current line */

  while ((len = get_line(line, MAXLINE)) > 0) {
    trim_line(line, len);
    test_print(line, len);
  }
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

void trim_line(char line[], int len) {
  /* 2 here is significant,
   * as the last two characters are always '\n' and '\0' */
  for (len = len - 2; len >= 0 && (line[len] == ' ' || line[len] == '\t');
       len--)
    line[len] = '\0';
}

void test_print(char line[], int length) {
  for (int i = 0; i < length; i++) {
    if (line[i] == '\0') /* string terminates at first '\0' */
      putchar('*');
    else
      putchar(line[i]);
  }

  putchar('\n');
}
