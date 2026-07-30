// Longest line implementatoin has an edge case, when the line is exactly the
// same length as max, the next get line returns 0 upon enter
#include <stdio.h>

#define MAXLINE 10
#define NO 0
#define YES 1

int get_line(char s[], int lim);
void copy(char from[], char to[]);
void print_line_vertically(char s[]);

int main() {
  char current_line[MAXLINE];
  char temp_line[MAXLINE];
  char longest_line[MAXLINE];
  int current_len = 0;
  int temp_len = 0;
  int longest_len = 0;
  int has_ended = YES;

  while ((current_len = get_line(current_line, MAXLINE)) > 0) {
    temp_len = temp_len + current_len;

    if (has_ended) {
      copy(current_line, temp_line);
    }

    if ((current_len == MAXLINE - 1) && current_line[MAXLINE - 2] != '\n' &&
        current_line[MAXLINE - 2] != EOF) {
      has_ended = NO;
    } else {
      has_ended = YES;

      if (temp_len > longest_len) {
        copy(temp_line, longest_line);
        longest_len = temp_len;
      }

      temp_len = 0; // reset
    }
  }

  printf("The longest line is %s\n", longest_line);
  printf("It has the length %d\n", longest_len);

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

void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void print_line_vertically(char s[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '\n')
      printf("\\n");
    else
      putchar(s[i]);

    putchar('\n');
  }
}
