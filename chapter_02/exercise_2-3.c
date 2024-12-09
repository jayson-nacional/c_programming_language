/* Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F. */

/* idea -> have validate method that return int
 * 0 if invalid */

#include <stdio.h>

enum boolean { NO, YES };
int atoi(char s[]);
int validate(char s[]);

int main() {
  char s[10];
  s[0] = 'c';
  s[1] = 'F';
  s[2] = '\0';

  int len = validate(s);
  printf("Output: %d\n", len);

  // next problem
  // how to map the values from 0-9, a-f, A-F to numerical equivalence
}

int validate(char s[]) {
  int len = 0;
  for (; s[len] != '\0'; len++) {
    if (s[len] >= '0' && s[len] <= '9' || s[len] >= 'a' && s[len] <= 'f' ||
        s[len] >= 'A' && s[len] <= 'F')
      ;
    else
      return 0;
  }

  return len;
}
