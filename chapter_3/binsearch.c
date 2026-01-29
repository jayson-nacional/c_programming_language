// Binary search first compares the input value of x to the middle element of
// the array v. If x is less than the middle value, searching focuses on the
// lower half of the table, otherwise on the upper half. In either case, the nex
// step is to compare x to the middle element of the selected half. This process
// of dividing the range in two continues until the value is found or the range
// is empty
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int v[5];

  v[0] = 3;
  v[1] = 6;
  v[2] = 9;
  v[3] = 12;
  v[4] = 15;

  printf("output: %d\n", binsearch(12, v, 5));

  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid + 1;
    else if (x > v[mid])
      low = mid + 1;
    else /* found match */
      return mid;
  }

  return -1; /* no match */
}
