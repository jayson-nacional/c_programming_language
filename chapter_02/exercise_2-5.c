/* Write the function any(s1, s2), which returns the first location in a string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2. (The standard library function strpbrk does the same job
 * but returns a pointer to the location.) */

#include <stdio.h>

int get_char_index(char s[], char c);
int any(char s1[], char s2[]);

int main() {
  char s1[100];
  s1[0] = 'a';
  s1[1] = 'b';
  s1[2] = 'c';
  s1[3] = '\0';

  char s2[100];
  s2[0] = 'd';
  s2[1] = 'e';
  s2[2] = 'b';
  s2[3] = '\0';

  int output = any(s1, s2);
  printf("Output: %d\n", output);
  return 0;
}

int get_char_index(char s[], char c) {
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return i;

  return -1;
}

int any(char s1[], char s2[]) {
  for (int i = 0; s1[i] != '\0'; i++)
    if (get_char_index(s2, s1[i]) != -1)
      return i;

  return -1;
}
