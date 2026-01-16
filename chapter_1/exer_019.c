// Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

int main() {
  int len = 0;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line);
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

void reverse(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; ++i)
    ;

  while (i >= 0)
    putchar(s[i--]);

  putchar('\n');
}
