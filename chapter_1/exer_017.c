// Write a program to print all input lines that are longer than 80 characters

#include <stdio.h>

#define MAXLINE 10
#define IN 1    /* inside the line */
#define OUT 0   /* outside the line */
#define BASE 80 /* base of line char count to be printed */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  char line[MAXLINE];
  char line_start[MAXLINE]; /* placeholder for the start of line */

  int state = OUT;
  int current_line_length = 0;

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (state == OUT)
      copy(line_start,
           line); /* stores the start of line in case this is longest */

    if (line[len - 1] != '\n') /* means has not reached the end of line yet */
      state = IN;
    else
      state = OUT;

    current_line_length = current_line_length + len;
    if (state == OUT) {
      if (current_line_length > BASE) {
        printf("%s\n", line_start);
      }

      current_line_length = 0;
    }
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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
