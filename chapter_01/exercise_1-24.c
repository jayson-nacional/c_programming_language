/* Write a program to check a C program for rudimentary syntax errors like
 * unmatched parentheses, brackets and braces. Don't forget about quotes, both
 * single and double, escape sequences, and comments. */

#include <stdio.h>

int main() {
  /* thought process
   * check for matching parentheses, brackets, braces
   * check for quotes, single and double
   * handle comments */
  char grouping_symbols[1000];
  int c;

  int i = 0;
  while ((c = getchar()) != EOF) {
    if (c == '(' || c == '[' || c == '{') {
      grouping_symbols[i] = c;
      i++;
    } else if (c == ')') {
      if (i <= 0)
        printf("Unmatched ) symbol");
      else if (grouping_symbols[i - 1] == '(')
        i--;
      else
        printf("Unmatched ( symbol");
    } else if (c == ']') {
      if (i <= 0)
        printf("Unmatched ] symbol");
      else if (grouping_symbols[i - 1] == '[')
        i--;
      else
        printf("Unmatched [ symbol");
    } else if (c == '}') {
      if (i <= 0)
        printf("Unmatched ] symbol");
      else if (grouping_symbols[i - 1] == '{')
        i--;
      else
        printf("Unmatched { symbol");
    }
  }

  return 0;
}
