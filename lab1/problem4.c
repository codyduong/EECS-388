#include <stdio.h>
#include <stdlib.h>

// int to decimal
long int itod (int n) {
  
  while (n)
}

/*
Prompts user input for a number and space seperated 0 or 1
for binary to hex or hex to binary respectively
*/
void main() {
  char input[20];
  int operator;
  long int base_10;

  printf("Input a value to be converted and a 0 or 1\nfor binary to hex or hex to binary respectively:\n");
  scanf("%s %d", input, &operator);
  switch (operator) {
    case 0:
      // use %X to format base_10 to base_16
      printf("%X\n", strtol(input, NULL, 2));
      break;
    case 1:
      // throw into a buffer to convert base_10 long into str
      base_10 = strtol(input, NULL, 16);

      // convert from base_10 to base_2
      printf("%ld\n", strtol(buffer, NULL, 2));
      break;
    default:
      printf("Expected either 0 or 1, not %d", operator);
  }
}