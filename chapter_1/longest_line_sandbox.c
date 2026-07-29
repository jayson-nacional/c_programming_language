#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void copy(char from[], char to[]);

int main() {
  char current_line[MAXLINE];
  char longest_line[MAXLINE];
  int longest_len = 0;
  int current_len = 0;

  while ((current_len = get_line(current_line, MAXLINE)) > 0) {
    if (current_len > longest_len) {
      copy(current_line, longest_line);
      longest_len = current_len;
    }
  }

  printf("%s\n", longest_line);

  return 0;
}

int get_line(char s[], int lim) {
  int c;
  int i = 0;

  for (; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (s[i] == '\n') {
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';

  return i;
}

void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
