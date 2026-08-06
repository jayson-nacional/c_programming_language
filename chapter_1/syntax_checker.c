#include <stdio.h>

#define IN_CODE 0
#define IN_CHAR 1
#define IN_STRING 2
#define IN_SINGLE_LINE_COMMENT 3
#define IN_MULTI_LINE_COMMENT 4
#define LENGTH 1000

int main() {
  int c, p; // where c = current, p = previous character
  char placeholder[LENGTH];
  int index = 0;

  placeholder[index] = '\0';
  int state = IN_CODE;
  while ((c = getchar()) != EOF) {
    if (state == IN_CODE) {
      if (c == '\'') {
        placeholder[index++] = '\'';
        placeholder[index] = '\0';
        state = IN_CHAR;
      } else if (c == '"') {
        placeholder[index++] = '"';
        placeholder[index] = '\0';
        state = IN_STRING;
      } else if (c == '/' && p == '/') {
        state = IN_SINGLE_LINE_COMMENT;
      } else if (c == '*' && p == '/') {
        state = IN_MULTI_LINE_COMMENT;
      } else if (c == '(') {
        placeholder[index++] = '(';
        placeholder[index] = '\0';
      } else if (c == '[') {
        placeholder[index++] = '[';
        placeholder[index] = '\0';
      } else if (c == '{') {
        placeholder[index++] = '{';
        placeholder[index] = '\0';
      } else if (c == ')') {
        if (placeholder[--index] == '(') {
          placeholder[index] = '\0';
        } else {
          printf("Mismatched %c\n", placeholder[index]);
          return 0;
        }
      } else if (c == ']') {
        if (placeholder[--index] == '[') {
          placeholder[index] = '\0';
        } else {
          printf("Mismatched %c\n", placeholder[index]);
          return 0;
        }
      } else if (c == '}') {
        if (placeholder[--index] == '{') {
          placeholder[index] = '\0';
        } else {
          printf("Mismatched %c\n", placeholder[index]);
          return 0;
        }
      }
    } else if (state == IN_CHAR) {
      if (c == '\'') {
        state = IN_CODE;

        if (placeholder[--index] == '\'') {
          placeholder[index] = '\0';
        } else {
          printf("Mismatched %c\n", placeholder[index]);
          return 0;
        }
      }
    } else if (state == IN_STRING) {
      if (c == '"') {
        state = IN_CODE;

        if (placeholder[--index] == '"') {
          placeholder[index] = '\0';
        } else {
          printf("Mismatched %c\n", placeholder[index]);
          return 0;
        }
      }
    } else if (state == IN_SINGLE_LINE_COMMENT) {
      if (c == '\n') {
        state = IN_CODE;
      }
    } else if (state == IN_MULTI_LINE_COMMENT) {
      if (c == '/' && p == '*') {
        state = IN_CODE;
      }
    }

    p = c;
  }

  if (index > 0) {
    printf("Syntax error! Mismatched %c\n", placeholder[index - 1]);
  } else {
    printf("Valid C program!\n");
  }

  return 0;
}
