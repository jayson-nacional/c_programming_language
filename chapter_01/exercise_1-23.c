#include <stdio.h>

/* Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't nest
 */

#define OUTSIDE_COMMENT 0
#define IN_SINGLE_LINE_COMMENT 1
#define IN_MULTI_LINE_COMMENT 2
#define INSIDE_STRING 3

int main() {
  int status = OUTSIDE_COMMENT;
  char program[1000];

  int c, p;
  int index = 0;
  while ((c = getchar()) != EOF) {
    if (status == OUTSIDE_COMMENT || status == INSIDE_STRING) {
      program[index] = c;
      index++;

      if (c == '"') {
        status = INSIDE_STRING;
      } else if (c == '/' && p == '/' && status != INSIDE_STRING) {
        status = IN_SINGLE_LINE_COMMENT;
        index = index - 2;
      } else if (c == '*' && p == '/' && status != INSIDE_STRING) {
        status = IN_MULTI_LINE_COMMENT;
        index = index - 2;
      }
    } else if (status == IN_SINGLE_LINE_COMMENT) {
      if (c == '\n')
        status = OUTSIDE_COMMENT;
    } else if (status == IN_MULTI_LINE_COMMENT) {
      if (c == '/' && p == '*')
        status = OUTSIDE_COMMENT;
    } else if (status == INSIDE_STRING) {
      if (c == '"')
        status = OUTSIDE_COMMENT;
    }

    p = c;
  }

  program[index] = '\0';
  printf("%s\n", program);

  return 0;
}
