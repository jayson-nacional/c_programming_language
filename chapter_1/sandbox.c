#include <stdio.h>

int get_line(char s[]);
void merge_spaces();
void word_count();

#define OUT 0
#define IN 1

int main() {
  word_count();
  return 0;
}

int get_line(char s[]) {
  int len = 0;

  for (int c; (c = getchar()) != EOF && c != '\n'; ++len)
    s[len] = c;

  s[len + 1] = '\0';

  return len;
}

void merge_spaces() {
  int c, p; // where c = current char; p = previous char
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (p != ' ' && p != '\t')
        putchar(' ');
    } else
      putchar(c);

    p = c;
  }
}

void word_count() {
  int wc = 0;
  int state = OUT;

  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++wc;
    }
  }

  printf("The number of words in input is %d\n", wc);
}
