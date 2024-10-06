#include <stdio.h>

/* Verify that the expression getchar() != EOF is 0 or 1 */
int main() {
  int expression = getchar() != EOF;
  printf("Expression output: %d\n", expression);

  return 0;
}
