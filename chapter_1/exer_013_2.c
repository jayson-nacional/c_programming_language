// Write a program to print a histogram of the lengths of words in its input. It
// is easy to draw the histogram with the bars horizontal; a vertical
// orientation is more challenging

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main() {
  int i, j, nw, inputLength, state, currentIndex;
  int wordCount[1000];
  int c;

  for (i = 0; i < 1000; ++i)
    wordCount[i] = 0;

  nw = inputLength = currentIndex = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    ++inputLength;

    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;
      ++currentIndex;
    } else {
      state = IN;
      ++nw;
      ++wordCount[currentIndex];
    }
  }

  // vertical histogram
  for (i = inputLength - 1; i >= 0; i--) {
    putchar('*');

    for (j = 0; j < nw; j++) {
      if (wordCount[j] > i)
        putchar('*');
      else
        putchar(' ');
    }

    putchar('\n');
  }

  return 0;
}
