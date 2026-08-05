#include <stdio.h>

#define IN_CODE 0
#define IN_STRING 1
#define IN_CHAR 2
#define IN_SINGLE_LINE_COMMENT 3
#define IN_MULTI_LINE_COMMENT 4

int main() {
  int state = IN_CODE;
  int c, p, pp; // where c = current, p = previous char, pp = previous previous
  int char_index = 0;

  while ((c = getchar()) != EOF) {
    if (state == IN_CODE) {
      if (c == '"')
        state = IN_STRING;
      else if (c == '\'')
        state = IN_CHAR;
      else if (c == '/' && p == '/')
        state = IN_SINGLE_LINE_COMMENT;
      else if (c == '*' && p == '/')
        state = IN_MULTI_LINE_COMMENT;

      if (state == IN_CODE) {
        if (p == '/' && pp != '*' && pp != '/') {
          putchar(p);
        }

        if (c != '/')
          putchar(c);
      } else if (state == IN_CHAR) {
        putchar(c);
      } else if (state == IN_STRING) {
        putchar(c);
      }
    } else if (state == IN_STRING) {
      putchar(c);
      if (c == '"')
        state = IN_CODE;
    } else if (state == IN_CHAR) {
      putchar(c);
      if (c == '\'')
        state = IN_CODE;
    } else if (state == IN_SINGLE_LINE_COMMENT) {
      if (c == '\n')
        state = IN_CODE;
    } else if (state == IN_MULTI_LINE_COMMENT) {
      if (c == '/' && p == '*')
        state = IN_CODE;
    }

    pp = p;
    p = c;
    ++char_index;
  }
}
