#include <stdio.h>

/* Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time */

#define MAXLINE 1000

int get_line(char line[], int limit);
void reverse(char line[], int length);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
    reverse(line, len);

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

void reverse(char line[], int length) {
  /* 2 represents '\n' and '\0' at end of line */
  length = length - 2;

	/* 2 here divides the line by half */
  int middle_point = (length - (length % 2)) / 2;

  int counterpart;

  for (int i = 0; i <= middle_point; i++) {
    counterpart = line[length - i];
    line[length - i] = line[i];
    line[i] = counterpart;
  }

  printf("%s", line);
}
