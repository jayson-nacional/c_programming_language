// Write a program to check a C program for rudimentary syntax errors like
// unmatched parentheses, brackets, and braces. Don't forget about quotes, both
// single and double, escape sequences, and comments. (This program is hard if
// you do it in full generality.)

#include <stdio.h>

#define IN_CODE 0
#define IN_CHAR 1
#define IN_STRING 2
#define IN_SINGLE_LINE_COMMENT 3
#define IN_MULTI_LINE_COMMENT 4
#define ERROR 5

int main() {
  int c, p, state;
  char grouping_symbols[1000];
  int symbols_buff_len = 0;

  state = IN_CODE;
  while ((c = getchar()) != EOF) {
    if (state == IN_CODE) {
      if (c == '\'')
        state = IN_CHAR;
      else if (c == '"')
        state = IN_STRING;
      else if (c == '/' && p == '/')
        state = IN_SINGLE_LINE_COMMENT;
      else if (c == '/' && p == '*')
        state = IN_MULTI_LINE_COMMENT;
    } else if (state == IN_CHAR) {
      if (c == '\'' && p != '\\')
        state = IN_CODE;
    } else if (state == IN_STRING) {
      if (c == '"' && p != '\\') {
        state = IN_CODE;
      }
    } else if (state == IN_SINGLE_LINE_COMMENT) {
      if (c == '\n')
        state = IN_CODE;
    } else if (state == IN_MULTI_LINE_COMMENT) {
      if (c == '/' && p == '*')
        state = IN_CODE;
    }

    if (state == IN_CODE) {
      if (c == '{' || c == '(' || c == '[') {
        grouping_symbols[symbols_buff_len++] = c;
      } else if (c == '}') {
        if (grouping_symbols[symbols_buff_len - 1] == '{') {
          --symbols_buff_len;
        } else {
          printf("Error: mismatched braces\n");
          state = ERROR;
        }
      } else if (c == ')') {
        if (grouping_symbols[symbols_buff_len - 1] == '(') {
          --symbols_buff_len;
        } else {
          printf("Error: mismatched parenthesis\n");
          state = ERROR;
        }
      } else if (c == ']') {
        if (grouping_symbols[symbols_buff_len - 1] == '[')
          --symbols_buff_len;
        else {
          printf("Error: mismatched brachets\n");
          state = ERROR;
        }
      }
    }

    p = c;
  }

  if (symbols_buff_len > 0) {
    printf("Error: mismatched pair for %c symbol\n",
           grouping_symbols[symbols_buff_len - 1]);
  } else if (state != ERROR)
    printf("Valid C code\n");
  else if (state == IN_CHAR)
    printf("Error: char block not closed\n");
  else if (state == IN_STRING)
    printf("Error: string block not closed\n");
  else if (state == IN_SINGLE_LINE_COMMENT)
    printf("Error: single line comment not closed\n");
  else if (state == IN_MULTI_LINE_COMMENT)
    printf("Error: multi line comment not closed\n");

  return 0;
}
