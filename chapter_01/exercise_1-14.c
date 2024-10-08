#include <stdio.h>

/* Write a program to print a histogram of the frequencies of different
 * characters in its input */
int main() {
  int c; /* current character */
  int input_length = 0;
  int character_frequencies[256];

  for (int i = 0; i < 256; i++)
    character_frequencies[i] = 0;

  while ((c = getchar()) != EOF) {
    ++input_length;

    ++character_frequencies[c];
  }

  /* input */
  printf(" I: ");
  for (int i = 0; i < input_length; i++)
    putchar('*');

  putchar('\n');
  /* end of input */

  for (int i = 0; i < 256; i++) {
    if (character_frequencies[i] > 0) {
      if (i == '\n')
        printf("\\n: ");
      else
        printf(" %c: ", i);

      for (int j = 0; j < character_frequencies[i]; j++)
        putchar('*');

      putchar('\n');
    }
  }

  printf("Input length: %d\n", input_length);

  return 0;
}
