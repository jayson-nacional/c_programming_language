#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int limit); /* return represents the line length */
void copy(char to[], char from[]);

int main() {
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) /* there was a line */
    printf("Longest: %s\n", longest);

  return 0;
}

/* get_line: read the line into line, return the length */
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}
