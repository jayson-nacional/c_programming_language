// Verify that the expression getchar() != EOF is 0 or 1

#include <stdio.h>

int main() {
  int isEndOfFile = getchar() != EOF;
  printf("Is end of file: %d\n", isEndOfFile);

  return 0;
}
