#include <stdio.h>

/* How would you test the word count program?
 * What kinds of input are most likely to uncover bugs if there are any? */
#define OUT 0 /* outside word */
#define IN 1  /* inside word */
int main() {
  int c;           /* current character */
  int state = OUT; /* determines the position in input */
  long word_count = 0;

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

/* Answer */

/* Dashed combination of words would likely result in wrong count, i.e
 * short-term, full-scale */

/* Mathematical expressions would also result in inconsistent count depending on
 * how spaces are written */
