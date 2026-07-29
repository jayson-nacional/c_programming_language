#include <stdio.h>

int get_line(char s[]);
void merge_spaces();
void word_count();
void one_word_per_line();
void horizontal_word_histogram();
void vertical_word_histogram();
int power(int m, int n);

#define OUT 0
#define IN 1

int main() {
  printf("2 raised to the power of 5 is %d\n", power(2, 5));
  return 0;
}

int get_line(char s[]) {
  int len = 0;

  for (int c; (c = getchar()) != EOF && c != '\n'; ++len)
    s[len] = c;

  s[len + 1] = '\0';

  return len;
}

void merge_spaces() {
  int c, p; // where c = current char; p = previous char
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (p != ' ' && p != '\t')
        putchar(' ');
    } else
      putchar(c);

    p = c;
  }
}

void word_count() {
  int wc = 0;
  int state = OUT;

  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++wc;
    }
  }

  printf("The number of words in input is %d\n", wc);
}

void one_word_per_line() {
  int c, p; // where c = current char, p = previous char
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (p != ' ' && p != '\t' && p != '\n')
        putchar('\n');
    } else {
      putchar(c);
    }

    p = c;
  }
}

void horizontal_word_histogram() {
  int c, p; // where c = current char, p = previous char
  int input_length = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (p != ' ' && p != '\t' && p != '\n')
        putchar('\n');
    } else {
      putchar('*');
    }

    p = c;
    ++input_length;
  }

  for (int i = 0; i < input_length; i++)
    putchar('*');

  putchar('\n');
}

void vertical_word_histogram() {
  int c, p; // where c = current char, p = previous char
  int input_length = 0;
  char word_lengths[1000];
  int length_index = 0;

  for (; length_index < 1000; length_index++)
    word_lengths[length_index] = 0;

  length_index = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (p != ' ' && p != '\t' && p != '\n')
        ++length_index;
    } else {
      ++word_lengths[length_index];
    }

    p = c;
    ++input_length;
  }

  while (input_length > 0) {
    putchar('*');

    for (length_index = 0; word_lengths[length_index] != 0; length_index++) {
      if (input_length > word_lengths[length_index])
        putchar(' ');
      else
        putchar('*');
    }

    putchar('\n');
    --input_length;
  }
}

int power(int m, int n) {
  int result = 1;

  while (n > 0) {
    result = result * m;
    --n;
  }

  return result;
}
