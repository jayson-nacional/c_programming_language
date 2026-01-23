// Write an alternative version of squeeze(s1, s2) that deletes each character
// in s1 that matches any character in the string 2

#include <stdio.h>

int get_index(char s[], char c);
void squeeze(char s1[], char s2[]);

int main() {
  char s1[5];
  char s2[5];

  s1[0] = 'a';
  s1[1] = 'b';
  s1[2] = 'c';
  s1[3] = 'd';
  s1[4] = '\0';

  s2[0] = 'a';
  s2[1] = 'b';
  s2[2] = 'e';
  s2[3] = 'f';
  s2[4] = '\0';

  squeeze(s1, s2);
  printf("%s\n", s1);

  return 0;
}

int get_index(char s[], char c) {
  int i;

  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == c)
      return i;
  }

  return -1;
}

void squeeze(char s1[], char s2[]) {
  int i, j;

  for (i = j = 0; s1[i] != '\0'; i++) {
    if (get_index(s2, s1[i]) == -1) {
      s1[j++] = s1[i];
    }
  }

  s1[j] = '\0';
}
