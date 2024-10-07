#include <stdio.h>

int main() {
  long nc;
  while (getchar() != EOF)
    ++nc;

  printf("Character count: %ld\n", nc);

  return 0;
}
