#include <stdio.h>

int main() {
  int ndigit[10];
  long nwhitespace, nother;
  int c;

  for (int i = 0; i < 10; i++)
    ndigit[i] = 0;

  nwhitespace = nother = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n')
      ++nwhitespace;
    else if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else
      ++nother;
  }

  for (int i = 0; i < 10; i++)
    printf("%d ", ndigit[i]);

  putchar('\n');
  printf("White space: %ld\n", nwhitespace);
  printf("Other characters: %ld\n", nother);

  return 0;
}
