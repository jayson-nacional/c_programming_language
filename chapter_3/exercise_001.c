// Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside.) Write a version with only one test inside
// the loop and measure the difference in run-time
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int limit = 1000;
  int v[limit];

  for (int i = 0; i < limit; i++)
    v[i] = i + 2;

  printf("output: %d\n", binsearch(10, v, limit));

  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low != high) {
    mid = (low + high) / 2;
    if (x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }

  if (x == v[mid])
    return mid;
  else if (x == v[mid + 1])
    return mid + 1;

  return -1; /* no match */
}
