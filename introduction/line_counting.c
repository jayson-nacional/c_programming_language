#include <stdio.h>

int main() {
  long c, nl; /* c = current character, nl = line count */

  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;

  printf("Line count: %ld\n", nl);

  return 0;
}
