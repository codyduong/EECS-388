#include <stdio.h>

/*
Uses primality test from wikipedia,
tests if divisible by 2/3 with no remainder.
Otherwise tests every number that isn't already divisible by 2 or 3, (so 6k+1)
that is below sqrt(n), since upper half is the same.

Local C target is set below C99, so there are no bools. RIP.
*/
int isPrime(int n) {
  if (n == 2 || n == 3) {
    return 1;
  }

  if (n <= 1 || n % 2 == 0 || n % 3 == 0) {
    return 0;
  }

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return 0;
    }
  }

  return 1;
}

/*
Takes in user input for upper bound (exclusive) and only prints out if it is prime
*/
void main () {
  int bound;

  printf("Input prime upper bound:\n");
  scanf("%d", &bound);

  int i;
  for (i = 0; i < bound; i++) {
    // printf("%d, ", i);
    if (isPrime(i) == 1) {
      printf("%d, ", i);
    }
  }
}