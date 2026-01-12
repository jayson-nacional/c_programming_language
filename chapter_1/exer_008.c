// Write a program to count blanks, tabs, and newlines

#include <stdio.h>

int main() {
  int c;
  int bc; /* blanks */
  int tc; /* tabs */
  int nc; /* newlines */

  bc = tc = nc = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++bc;
    else if (c == '\t')
      ++tc;
    else if (c == '\n')
      ++nc;
  }

  printf("Blanks: %d\n", bc);
  printf("Tabs: %d\n", tc);
  printf("Newlines: %d\n", nc);

  return 0;
}
