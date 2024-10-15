/* Challenge: find the most optimal algorithm */
#include <stdio.h>

/* Write a program to `fold` long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column. */
#define MAXLINE 1000
#define FOLD_LENGTH 20

int get_line(char line[], int limit);
void fold_line(char line[], int len);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    fold_line(line, len);
  }

  return 0;
}

void fold_line(char line[], int len) {
  char line_chunk[FOLD_LENGTH];
  char printable_chunk[FOLD_LENGTH];

  int current_index = 0;
  int i;
  for (i = 0; i < len; i++) {
    line_chunk[current_index] = line[i];

    if (current_index == FOLD_LENGTH - 1) {
      int irb; /* index of first blank from right */

      /* irb != -1 validates for scenarios where chunk has no blanks */
      for (irb = current_index;
           line_chunk[irb] != ' ' && line_chunk[irb] != '\t' && irb != -1;
           irb--) {
      }

      int irnb; /* index of 1st non blank char from left of irb */
      if (irb == -1) /* means that chunk has no blank */
        irb = FOLD_LENGTH - 1;

      for (irnb = irb; line_chunk[irnb] == ' ' || line_chunk[irnb] == '\t';
           irnb--)
        ;

      int j;
      for (j = 0; j <= irnb; j++)
        printable_chunk[j] = line_chunk[j];

      printable_chunk[j] = '\0';
      printf("%s\n", printable_chunk);

      int k;
      irb++;
      for (k = 0; irb <= current_index; irb++) {
        line_chunk[k] = line_chunk[irb];
        ++k;
      }

      current_index = k; /* reset line chunk index */
    } else {
      ++current_index;
    }
  }

  /* print last chunk if available */
  if (current_index > 0) {
    line_chunk[current_index] = '\0';
    printf("%s", line_chunk);
  }
}

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
