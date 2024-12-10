/* Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F. */

/* idea -> have validate method that return int as length
 * 0 if invalid */

#include <stdio.h>

enum boolean { NO, YES };
int atoi(char s[]);
int validate(char s[]);
int get_hex_equivalent(char s);

int main() {
  char s[10];
  s[0] = '3';
  s[1] = 'E';
  s[2] = '8';
  s[3] = '\0';

  int len = validate(s);
  if (len == 0)
    printf("Invalid input.\n");
  else {
    int output = get_hex_equivalent(s[0]);
    for (int i = 1; i < len; i++) {
      // get the hex value of the current character
      int current = get_hex_equivalent(s[i]);
      output = output * 16 + current;
    }

    printf("Output: %d\n", output);
  }
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

int get_hex_equivalent(char s) {
  if (s == '0')
    return 0;
  else if (s == '1')
    return 1;
  else if (s == '2')
    return 2;
  else if (s == '3')
    return 3;
  else if (s == '4')
    return 4;
  else if (s == '5')
    return 5;
  else if (s == '6')
    return 6;
  else if (s == '7')
    return 7;
  else if (s == '8')
    return 8;
  else if (s == '9')
    return 9;
  else if (s == 'a' || s == 'A')
    return 10;
  else if (s == 'b' || s == 'B')
    return 11;
  else if (s == 'c' || s == 'C')
    return 12;
  else if (s == 'd' || s == 'D')
    return 13;
  else if (s == 'e' || s == 'E')
    return 14;
  else if (s == 'f' || s == 'F')
    return 15;

  return -1; /* indicate wrong input */
}
