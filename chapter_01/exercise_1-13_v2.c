#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

/* vertical histogram */
int main() {
  int input_length = 0;
  int word_length_counter[1000];

  for (int i = 0; i < 1000; i++)
    word_length_counter[i] = 0;

  int current_counter_index = 0;

  int c; /* current character */
  int p; /* previous character */
  while ((c = getchar()) != EOF) {
    ++input_length;

    if (c == ' ' || c == '\t' || c == '\n') {
      if (p != ' ' && p != '\t' && p != '\n')
        ++current_counter_index;
    } else
      ++word_length_counter[current_counter_index];

    p = c;
  }

  int number_of_words = 0;
  for (int i = 0; word_length_counter[i] != 0; i++)
    ++number_of_words;

  // loop based on input length
  for (int i = input_length; i > 0; i--) {
    putchar('*');

    // loop through the words
    for (int j = 0; j < number_of_words; j++) {
      if (word_length_counter[j] >= i)
        putchar('*');
      else
        putchar(' ');
    }

    putchar('\n');
  }

  return 0;
}
