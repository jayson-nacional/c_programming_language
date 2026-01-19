// for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//	s[i] = c;
//
// Write a loop equivalent to the for loop above without using && or ||.

#include <stdio.h>
#define MAXLINE 1000

int main() {
  int i, c, state, lim;
  char s[MAXLINE];

  lim = MAXLINE;
  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) != '\n')
      if (c != EOF)
        s[i] = c;
  }

  return 0;
}
