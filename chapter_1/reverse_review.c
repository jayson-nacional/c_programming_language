// TODO: compare the performance when using modulus approach

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void reverse(char s[]);

int main() {
  char current_line[MAXLINE];
  int current_len = 0;
  while ((current_len = get_line(current_line, MAXLINE)) > 0) {
    reverse(current_line);
    printf("%s\n", current_line);
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c;
  int i = 0;

  for (; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (s[i] == '\n') {
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';

  return i;
}

void reverse(char s[]) {
  int last_index = 0;
  while (s[last_index] != '\0')
    ++last_index;

  --last_index;
  int first_index = 0;

  char temp_last;

  while (first_index < last_index) {
    temp_last = s[last_index];
    s[last_index--] = s[first_index];
    s[first_index++] = temp_last;
  }
}
