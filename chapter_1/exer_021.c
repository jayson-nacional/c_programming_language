// Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing. Use the same tab stops as for
// detab. When either a tab or a single blank would suffice to reach a tab stop,
// which should be given preference?

#include <stdio.h>

#define TAB_STOP 4
#define MAXLINE 1000

int get_line(char s[], int lim);
void entab(char s[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    entab(line);
    putchar('\n');
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void entab(char s[]) {
  int i;
  int number_of_blanks;

  i = 0;
  number_of_blanks = 0;
  while (s[i] != '\0') {
    ++number_of_blanks;

    if (number_of_blanks > TAB_STOP) {
      putchar('\t');
      number_of_blanks = 0;
    }

    ++i;
  }

  if (number_of_blanks > 0) {
    for (i = 0; i < number_of_blanks; i++)
      putchar(' ');
  }
}
