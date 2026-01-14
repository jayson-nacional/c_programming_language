// Revise the main routine of the longest-line program so it will correctly
// print the length of arbitrary long input lines, as as much as possible of the
// text

#include <stdio.h>

#define MAXLINE 10
#define IN 1  /* inside the line */
#define OUT 0 /* outside the line */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char line_start[MAXLINE]; /* placeholder for the start of line */
  char longest[MAXLINE];

  max = 0;
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
      if (current_line_length > max) {
        max = current_line_length;
        copy(longest, line_start);
      }

      current_line_length = 0;
    }
  }

  printf("Longest length: %d\n", max);
  printf("Longest line: %s\n", longest);

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
