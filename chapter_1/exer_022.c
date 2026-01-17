// Write a program to "fold" long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of
// input. Make sure your program does something intelligent with very long
// lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>

#define FOLD_LIMIT 10
#define MAXLINE 1000

int get_line(char s[], int lim);
void fold(char s[], int len);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    fold(line, len);
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void fold(char s[], int len) {
  int start_index;
  int last_blank_index;
  int last_nonblank_index;
  int fold_index;
  int i;

  start_index = last_blank_index = last_nonblank_index = 0;
  fold_index = start_index + FOLD_LIMIT - 1;

  while (len > fold_index) {
    for (i = fold_index; s[i] != ' '; --i)
      ;
    last_blank_index = i;

    if (last_blank_index > 0) {
      for (i = last_blank_index; s[i] == ' '; --i)
        ;
      last_nonblank_index = i;

      for (i = start_index; i <= last_nonblank_index; ++i)
        putchar(s[i]);

      putchar('\n');

      start_index = last_blank_index + 1;
      fold_index = start_index + FOLD_LIMIT;
    } else { /* means very long line with no blanks */
      for (i = start_index; i < fold_index; ++i)
        putchar(s[i]);

      putchar('-');
      putchar('\n');

      start_index = fold_index;
      fold_index = start_index + FOLD_LIMIT;
    }
  }

  // print the remaining chars
  for (i = start_index; s[i] != '\0'; ++i)
    putchar(s[i]);

  putchar('\n');
}
