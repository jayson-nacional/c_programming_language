/* Write a loop equivalent to the for loop below without using && or || */

//  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
//    line[i] = c;
#include <stdio.h>
#define MAXLINE 1000
enum boolean { NO, YES };

int main() {
  int c;
  int i;
  int limit = MAXLINE;
  char line[MAXLINE];

  int should_terminate = NO;
  for (i = 0; should_terminate == NO; i++) {
    if (i >= limit - 1)
      should_terminate = YES;
    else if ((c = getchar()) == EOF)
      should_terminate = YES;
    else if (c == '\n')
      should_terminate = YES;

    line[i] = c;
  }

  line[i] = '\0';
  printf("Line: %s\n", line);
}
