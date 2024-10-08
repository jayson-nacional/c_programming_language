#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

/* horizontal histogram */
int main() {
  int input_length = 0;
  int word_length_counter[1000];

  for (int i = 0; i < 1000; i++)
    word_length_counter[i] = 0;

  int c; /* current character */
  int p; /* previous character */
  int length_counter_index = 0;
  while ((c = getchar()) != EOF) {
    ++input_length;

    if (c == ' ' || c == '\t' || c == '\n') {
      if (p != ' ' && p != '\t' && p != '\n')
        ++length_counter_index;
    } else
      ++word_length_counter[length_counter_index];

    p = c;
  }

  /* input matrix */
  for (int i = 0; i < input_length; i++)
    putchar('*');

  putchar('\n');
  /* end of input */

  for (int i = 0; word_length_counter[i] != 0; i++) {
    for (int j = 0; j < word_length_counter[i]; j++)
      putchar('*');

    putchar('\n');
  }

  return 0;
}
