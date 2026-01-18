// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments don't nest

#include <stdio.h>

#define IN_CODE 0
#define IN_STRING 1
#define IN_CHAR 2
#define IN_SINGLE_LINE_COMMENT 3
#define IN_MULTI_LINE_COMMENT 4

int main() {
  int c, p;
  int state = IN_CODE;
  while ((c = getchar()) != EOF) {
    // setting state
    if (state == IN_CODE) {
      if (c == '"')
        state = IN_STRING;
      else if (c == '\'')
        state = IN_CHAR;
      else if (c == '/' && p == '/')
        state = IN_SINGLE_LINE_COMMENT;
      else if (c == '*' && p == '/')
        state = IN_MULTI_LINE_COMMENT;
    } else if (state == IN_STRING) {
      if (c == '"')
        state = IN_CODE;
    } else if (state == IN_CHAR) {
      if (c == '\'')
        state = IN_CODE;
    } else if (state == IN_SINGLE_LINE_COMMENT) {
      if (c == '\n')
        state = IN_CODE;
    } else if (state == IN_MULTI_LINE_COMMENT) {
      if (c == '/' && p == '*')
        state = IN_CODE;
    }

    // output
    if (state == IN_CODE) {
      if (c != '/')
        putchar(c);
      else if (p == '/' && (c != '/' || c != '*'))
        putchar(c);
    } else if (state == IN_CHAR || state == IN_STRING) {
      putchar(c);
    }

    p = c;
  }

  return 0;
}
