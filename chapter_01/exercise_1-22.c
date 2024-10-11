#include <stdio.h>

/* Write a program to `fold` long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column. */

#define MAXLINE 1000
#define FOLD_INDEX 10

int get_line(char line[], int limit);
void fold_line(char line[], int len);

int main() { return 0; }

int get_line(char line[], int limit) {
  int i, c;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void fold_line(char line[], int len) {
  char line_chunk[FOLD_INDEX]; /* store the folded chunks */

  int i = 0; /* cursor position in line */
  int chunk_length = 0;
  while (len > i) {
    line_chunk[i] = line[i];
    ++chunk_length;

    if (chunk_length == FOLD_INDEX) { /* chunk is full, fold here */
      /* loop to get the first blank from right */
      int irb; /* index from right to get first blank */
      for (irb = chunk_length - 1;
           line_chunk[irb] != ' ' && line_chunk[irb] != '\t'; irb--)
        ;

      int irnb; /* index from right to get the first non-blank character */
      for (irnb = irb; line_chunk[irnb] == ' ' || line_chunk[irnb] == '\t';
           irnb--)
        ;
    }

    ++i;
  }
}
