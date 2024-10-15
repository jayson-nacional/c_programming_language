#include <stdio.h>

/* Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't nest
 */
#define INSIDE_SINGLE_LINE_COMMENT 1
#define INSIDE_MULTI_LINE_COMMENT 1
#define OUTSIDE_COMMENT 0
int main() {
  int c;  /* current character */
  int p;  /* previous character */
  char c_program[1000];

  int index = 0;
  int state = OUTSIDE_COMMENT;
  while ((c = getchar()) != EOF) {
    if (state == OUTSIDE_COMMENT) {
      if (c == '/' && p == '/') {
        if (index != 0)
          --index;

        state = INSIDE_SINGLE_LINE_COMMENT;
      } else if (c == '/' && p != '/') {
        c_program[index] = c;
        ++index;
      } else {
        c_program[index] = c;
        ++index;
      }
    } else {
      if (state == INSIDE_SINGLE_LINE_COMMENT && c == '\n')
        state = OUTSIDE_COMMENT;
    }

    p = c;
  }

  c_program[index] = '\0';
  printf("%s", c_program);

  return 0;
}
