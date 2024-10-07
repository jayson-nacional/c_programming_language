#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines */
int main() {
  int c;	/* current character */
  long tab_count, blank_count, newline_count;

  tab_count = blank_count = newline_count = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t')
      ++tab_count;
    else if (c == ' ')
      ++blank_count;
    else if (c == '\n')
      ++newline_count;
  }

  printf("Tab count: %ld\n", tab_count);
  printf("Blank count: %ld\n", blank_count);
  printf("Newline count: %ld\n", newline_count);

  return 0;
}
