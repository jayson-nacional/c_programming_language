#include <stdio.h>

/* Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrary long input lines, and as much as possible of
 * the text */

#define MAXLINE 30

int get_line(char line[], int limit);
void copy(char to[], char from[]);

int main() {
  int len;         /* current line length */
  int max;         /* max seen line length */
  int temp_length; /* accumulate length of very long lines */

  int line_chunk;
  char line[MAXLINE];         /* store current line */
  char longest[MAXLINE];      /* storage longest line */
  char temp_longest[MAXLINE]; /* store first chunk of very long lines */

  max = temp_length = line_chunk = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    temp_length = temp_length + len;

    /* if true, indicates that end of line has not not been reached yet */
    if (line[MAXLINE - 2] != '\n' && len == MAXLINE - 1) {
      if (line_chunk == 0) /* store only the first chunk */
        copy(temp_longest, line);
      ++line_chunk;
    } else {
      if (temp_length > max) {
        max = temp_length;

        if (line_chunk > 0)
          copy(longest, temp_longest);
        else
          copy(longest, line);

        line_chunk = 0;
        temp_length = 0;
      }
    }
  }

  if (max > 0) {
    printf("Length of longest line: %d\n", max);
    printf("Longest line: %s\n", longest);
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

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
