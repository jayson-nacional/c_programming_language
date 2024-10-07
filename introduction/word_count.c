#include <stdio.h>

#define OUT 0
#define IN 1
int main() {
  int c;     /* current character */
  int state; /* determines the position in input */
  long word_count;

  word_count = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++word_count;
    }
  }

  printf("Word count: %ld\n", word_count);

  return 0;
}
