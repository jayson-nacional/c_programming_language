/* Write an alternative version of squeeze(s1, s2) that deletes each character
 * in s1 that matches any character in the string s2 */
#include <stdio.h>

void squeeze_v1(char s[], char c);
void squeeze(char s1[], char s2[]);
int get_char_index(char s[], char c);

int main() {
  printf("Testing program...\n");
  char line[100];
  line[0] = 'a';
  line[1] = 'b';
  line[2] = 'c';
  line[3] = '\0';

  char line2[100];
  line2[0] = 'c';
  line2[1] = 'd';
  line2[2] = 'e';
  line2[3] = '\0';

  squeeze(line, line2);
  printf("%s\n", line);
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int j = 0;

  for (int i = 0; s1[i] != '\0'; i++) {
    if (get_char_index(s2, s1[i]) == -1)
      s1[j++] = s1[i];
  }

  s1[j] = '\0';
}

void squeeze_v1(char s[], char c) {
  int j = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] != c)
      s[j++] = c;
  }

  s[j] = '\0';
}

int get_char_index(char s[], char c) {
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return i;

  return -1;
}
