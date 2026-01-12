// How would you test the word count program? What kinds of input are most
// likely to uncover bugs if there are any?
//
// This solution mostly works for text content. The count might not be that
// accurate for complicated inputs such as code and numerical contents
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main() {
  int c;
  int nc, nl, nw;
  int state;

  nc = nl = nw = 0;

  state = OUT;
  while ((c = getchar()) != EOF) {
    ++nc;

    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("Number of characters: %d\n", nc);
  printf("Number of lines: %d\n", nl);
  printf("Number of words: %d\n", nw);

  return 0;
}
