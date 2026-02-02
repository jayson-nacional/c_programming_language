// Write a function expand(s1, s2) that expands shorthand notations like a-z in
// the string s1 into the equivalent complete list abc...xyz in s2. Allow for
// letters of either case and digits, and be prepared to handle cases like a-b-c
// and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally

#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
  int limit = 1000;
  char s1[limit];
  char s2[limit];
  s1[0] = 'a';
  s1[1] = '-';
  s1[2] = 't';
  s1[3] = '0';
  s1[4] = '-';
  s1[5] = '9';
  s1[6] = '\0';

  // s1[0] = 'a';
  // s1[1] = '-';
  // s1[2] = 'b';
  // s1[3] = '-';
  // s1[4] = '-';
  // s1[5] = '\0';

  expand(s1, s2);
  printf("Output: %s\n", s2);

  return 0;
}

void expand(char s1[], char s2[]) {
  int i, j, k;

  j = 0;
  for (i = 0; s1[i] != '\0'; i++) {
    if (s1[i] == '-') {
      if (i == 0) // print dash prefixes
        s2[j++] = s1[i];
      else if ((s1[i - 1] + 1) ==
               s1[i + 1]) // chars beside the dash are consecutive
        s2[j++] = s1[i];
      else if (i > 0 && s1[i - 1] == '-') // consecutive dash
        s2[j++] = s1[i];
      else {
        if (s1[i - 1] < s1[i + 1]) { // valid sequence
          for (int k = i - 1; s1[k] < s1[i + 1]; s1[k]++) {
            s2[j++] = s1[k];
          }
        } else { // invalid sequence
          s2[j++] = s1[i];
        }
      }
    } else {
      if ((s1[i] + 1) < s1[i + 2]) // skip reprinting the first char of sequence
        ;
      else
        s2[j++] = s1[i];
    }
  }

  s2[j] = '\0';
}
