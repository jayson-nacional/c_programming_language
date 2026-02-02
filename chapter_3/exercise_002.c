// Write a function escape (s, t) that converts characters like newline and tab
// into visible escape sequences like \n and \t as it copies the string t to s.
// Use a switch. Write a function for the other direction as well, converting
// escape sequences into real characters.

#include <stdio.h>

void escape(char t[], char s[]);
void transform_blanks(char t[], char s[]);

int main() {
  int limit = 1000;
  char t[limit];
  char s[limit];
  int i;

  i = 0;
  t[i] = 'a' + i;

  int distance = 'z' - 'a';
  for (i = 0; i <= distance; i++)
    t[i] = 'a' + i;

  t[5] = '\n';
  t[11] = '\t';

  escape(t, s);
  printf("%s\n", s);
  transform_blanks(s, t);
  printf("%s\n", t);

  return 0;
}

void escape(char t[], char s[]) {
  int i, j;

  i = j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    default:
      s[j++] = t[i];
      break;
    }

    i++;
  }

  s[j] = '\0';
}

void transform_blanks(char t[], char s[]) {
  int i, j;

  i = j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
    case '\\':
      if (t[i + 1] == 'n')
        s[j++] = '\n';
      else if (t[i + 1] == 't')
        s[j++] = '\t';
      break;
    default:
      s[j++] = t[i];
      break;
    }

    i++;
  }

  s[j] = '\0';
}
