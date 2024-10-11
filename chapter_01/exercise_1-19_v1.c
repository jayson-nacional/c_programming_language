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

/* this implementation is quite inefficient as it creates new array
 * this can be optimized by using single array
 * in combination with modulus operator - fold like structure
 * see exercise_1-19_v2.c */
void reverse(char line[], int length) {
  char reversed[length];

  --length; /* last character represents '\0' terminator */
  for (int i = 0; i < length; i++)
    reversed[i] = line[length - 1 - i]; /* -1 ensures '\n' is not included */

  printf("%s", reversed);
}
