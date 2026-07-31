#include <stdio.h>

#define MAXLINE 15

int main() {
  char line[MAXLINE];
  int c;

  int space_index = 0;
  int line_index = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      space_index = line_index;
    }

    if (line_index == MAXLINE - 1) {
      if (space_index == 0) {
        line[line_index] = '\0';
        printf("%s-\n", line);
        line_index = space_index = 0;
      } else {
        line[space_index] = '\0';
        printf("%s\n", line);

        int walker = 0;
        while (++space_index < line_index) {
          line[walker++] = line[space_index];
        }

        line_index = walker;
        space_index = 0;
      }
    }

    line[line_index++] = c;
  }

  if (line_index > 0) {
    line[line_index] = '\0';
    printf("%s\n", line);
  }
}
