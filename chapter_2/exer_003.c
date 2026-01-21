// Write a function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The
// allowable digits are 0 through 9, a through f, and A through F.

#include <stdio.h>

#define WORDLENGTH 255

int get_word(char s[]);

int main() {
  // get the word first, then per word process the hex
  int len;
  char word_buffer[WORDLENGTH];

  while ((len = get_word(word_buffer)) > 0) {
    printf("current length: %d\n", len);
    printf("%s\n", word_buffer);

    // TODO: create a function to get the hex from word (sort of validation as
    // well)
    // implement the conversion to decimal using the formula
  }

  return 0;
}

int get_word(char s[]) {
  int i, c;

  i = 0;
  for (i = 0; (c = getchar()) != EOF && c != ' ' && c != '\t' && c != '\n'; i++)
    s[i] = c;

  s[i] = '\0';
  return i;
}
