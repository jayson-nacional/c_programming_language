// Write a program to print a histogram of the lengths of words in its input. It
// is easy to draw the histogram with the bars horizontal; a vertical
// orientation is more challenging

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main() {
  int i, inputLength, state;
  int wordCount[1000];
  int c;

  for (i = 0; i < 1000; ++i)
    wordCount[i] = 0;

  inputLength = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    ++inputLength;

    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else {
      state = IN;
      // TODO:: while state is in increment the count of the current index in
      // word count on out:: increase the index of the current count -> to add
      // index variable
    }
  }

  printf("Input length: %d\n", inputLength);

  return 0;
}
