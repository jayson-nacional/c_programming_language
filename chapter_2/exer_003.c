// Write a function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The
// allowable digits are 0 through 9, a through f, and A through F.

#include <math.h>
#include <stdio.h>

#define MAX_LENGTH 1000

int htoi(char s[]);
int get_word(char s[]);
int get_hex(char s);

int main() {
  int len;
  char word[MAX_LENGTH];

  while ((len = get_word(word)) > 0) {
    printf("Hexadecimal value: %d\n", htoi(word));
  }

  return 0;
}

int htoi(char s[]) {
  int i, hex_length, start_index, result;

  hex_length = start_index = result = 0;
  for (hex_length = 0; s[hex_length] != '\0';
       hex_length++) /* validation can be added here to make sure only hex
                        values are accepted */
    ;

  if (hex_length > 2) {
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
      start_index = 2;
  }

  for (i = 0; start_index < hex_length; i++) {
    if ((s[start_index] >= '0' && s[start_index] <= '9') ||
        (s[start_index] >= 'a' && s[start_index] <= 'f') ||
        (s[start_index] >= 'A' && s[start_index] <= 'F')) {
      result = result + (get_hex(s[start_index]) *
                         pow(16, (hex_length - start_index - 1)));
    } else {
      return result; /* this has a bug if the succeeding characters is not a
                        valid hex value - best approach is to validate hex first
                        before converting */
    }

    start_index++;
  }

  return result;
}

int get_word(char s[]) {

  int i, c;

  for (i = 0; (c = getchar()) != EOF && c != ' ' && c != '\t' && c != '\n'; i++)
    s[i] = c;

  s[i] = '\0';

  return i;
}

int get_hex(char s) {
  if (s >= '0' && s <= '9')
    return s - '0';
  else if (s >= 'a' && s <= 'f')
    return s - 'a';
  else if (s >= 'A' && s <= 'F')
    return s - 'A';

  return -1;
}
