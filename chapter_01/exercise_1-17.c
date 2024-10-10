#include <stdio.h>

/* Write a program to print all input lines that are longer than 10 characters
 */
#define REQUIRED_LENGTH_TO_PRINT 10
#define MAXLINE 1000

int get_line(char line[], int limit);
void copy(char to[], char from[]);
void print_until(char line[], int last_index);

int main() {
  int len; /* current line length */
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > REQUIRED_LENGTH_TO_PRINT)
      /* print_until ensures that if previous lines are longer than current it
       * only prints until current length */
      print_until(line, len);
  }
}

int get_line(char line[], int limit) {
  int i, c;
  for (i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void print_until(char line[], int last_index) {
  for (int i = 0; i < last_index; i++)
    putchar(line[i]);

  putchar('\n');
}
