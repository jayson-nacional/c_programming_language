/* Write a program to check a C program for rudimentary syntax errors like
 * unmatched parentheses, brackets and braces. Don't forget about quotes, both
 * single and double, escape sequences, and comments. */

#include <stdio.h>

#define IN_CODE 1
#define IN_STRING 2
#define IN_CHAR 3

int main() {
  /* thought process
   * escape sequences and single quotes
   * handle comments */
  char grouping_symbols[1000];
  int c;

  int state = IN_CODE;
  int i = 0;
  while ((c = getchar()) != EOF) {
    if (c == '"' && state == IN_CODE)
      state = IN_STRING;
    else if (c == '"' && state == IN_STRING)
      state = IN_CODE;
    else if (c == '\'' && state == IN_CODE)
      state = IN_CHAR;
    else if (c == '\'' && state == IN_CHAR)
      state = IN_CODE;
    else if (state == IN_CODE && (c == '(' || c == '[' || c == '{')) {
      grouping_symbols[i] = c;
      i++;
    } else if (state == IN_CODE && c == ')') {
      if (i <= 0)
        printf("Unmatched ) symbol\n");
      else if (grouping_symbols[i - 1] == '(')
        i--;
      else
        printf("Unmatched ( symbol\n");
    } else if (state == IN_CODE && c == ']') {
      if (i <= 0)
        printf("Unmatched ] symbol\n");
      else if (grouping_symbols[i - 1] == '[')
        i--;
      else
        printf("Unmatched [ symbol\n");
    } else if (state == IN_CODE && c == '}') {
      if (i <= 0)
        printf("Unmatched } symbol\n");
      else if (grouping_symbols[i - 1] == '{')
        i--;
      else
        printf("Unmatched { symbol\n");
    }
  }

  printf("Value of i: %d", i);
  if (i > 0) {
    printf("Last value of unmatched symbol: %d\n", grouping_symbols[i]);
    putchar('\n');
  }

  return 0;
}
