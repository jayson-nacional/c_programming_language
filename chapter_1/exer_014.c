// Write a program to print a histogram of the frequencies of different
// characters in its input

#include <stdio.h>

#define CHAR_MAX 255

int main() {
  int chars[CHAR_MAX + 1];

  int inputLength;
  int c;
  int i, j;

  for (i = 0; i <= CHAR_MAX; i++)
    chars[i] = 0;

  inputLength = 0;
  while ((c = getchar()) != EOF) {
    ++inputLength;
    ++chars[c];
  }

  printf("Input ");
  for (i = 0; i < inputLength; i++)
    putchar('*');
  putchar('\n');

  for (i = 0; i <= CHAR_MAX; i++) {
    if (chars[i] > 0) { /* render the char count */
      if (i == ' ')
        printf("   sp ");
      else if (i == '\t')
        printf("   \\t");
      else if (i == '\n')
        printf(" rtrn ");
      else
        printf("    %c ", i);

      for (j = 0; j < chars[i]; j++)
        putchar('*');

      putchar('\n');
    }
  }

  return 0;
}
