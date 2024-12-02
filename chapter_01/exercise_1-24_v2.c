/* Write a program to check a C program for rudimentary syntax errors like
 * unmatched parentheses, brackets and braces. Don't forget about quotes, both
 * single and double, escape sequences, and comments. */
#define IN_CODE 1
#define IN_STRING 2
#define IN_CHAR 3

#include <stdio.h>

int main() {
  char grouping_symbols[1000];
  int index = 0;
  int state = IN_CODE;
  int c;  /* current character */
  int p;  /* previous character */
  int bp; /* before previous character */

  while ((c = getchar()) != EOF) {
    if (state == IN_CODE) {
      if (c == '"')
        state = IN_STRING;
      else if (c == '\'')
        state = IN_CHAR;
      else if (c == '(' || c == '{' || c == '[') {
        grouping_symbols[index] = c;
        index++;
      } else if (c == ')') {
        if (c == ')' && grouping_symbols[index - 1] == '(')
          index--;
        else
          printf("Unmatched parenthesis\n");
      } else if (c == '}') {
        if (c == '}' && grouping_symbols[index - 1] == '{')
          index--;
        else
          printf("Unmatched braces\n");
      } else if (c == ']') {
        if (c == ']' && grouping_symbols[index - 1] == '[')
          index--;
        else
          printf("Unmatched brackets\n");
      }
    } else if (state == IN_STRING) {
      if (c == '"' && p != '\\')
        state = IN_CODE;
    } else if (state == IN_CHAR) {
      if (c == '\'' && p != '\\')
        state = IN_CODE;
    }

    bp = p;
    p = c;
  }

  if (index == 0)
    printf("Valid code\n");
  else
    printf("Unmatched symbol: %c\n", grouping_symbols[index - 1]);

  return 0;
}
