#include <stdio.h>

int main() {
  /*
   * Experiment to find out what happens when print's argument string contains
   * \c, where c is some character not listed above
   */
  printf("tab, \t");
  printf("newline, \n");
  return 0;
}
