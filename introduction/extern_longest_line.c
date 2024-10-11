#include <stdio.h>

#define MAXLINE 1000

int max;               /* longest length seen so far */
char line[MAXLINE];    /* where current line is stored */
char longest[MAXLINE]; /* where longest line is stored */

int get_line(void);
void copy(void);

int main() {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = get_line()) > 0) {
    if (len > max) {
      copy();
      max = len;
    }
  }

  if (max > 0)
    printf("Longest: %s", longest);

  return 0;
}

int get_line(void) {
  int i, c;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void copy(void) {
  extern char line[];
  extern char longest[];

  for (int i = 0; (longest[i] = line[i]) != '\0'; i++)
    ;
}
