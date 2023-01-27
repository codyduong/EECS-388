#include <stdio.h>
#include <stdlib.h>

/*
Long int to binary string
*/
void ltobs(long int v, char *word) {
  long int temp_decimal;
  // just dont go above 64 binary digits
  int binary_reverse[64] = { 0 };
  int i = 0;

  temp_decimal = v;

  while (temp_decimal != 0) {
    // set the current index to the remainder
    // printf("%i", temp_decimal % 2);
    // we could just throw it right into the *word, but w/e
    binary_reverse[i] = temp_decimal % 2;
    temp_decimal = temp_decimal / 2;
    i++;
  }
  
  // reverse
  int array_length = sizeof(binary_reverse) / sizeof(int);
  int binary[64] = { 0 };
  for (int j = 0; j < array_length; j++) {
    int reverse_index = array_length - 1 - j;
    // printf("%i, %i, %i\n", j, reverse_index, binary_reverse[reverse_index]);
    word[j] = binary_reverse[reverse_index]+'0'; // this should cast to char
  }
}

/*
Prompts user input for a number and space seperated 0 or 1
for binary to hex or hex to binary respectively
*/
int main() {
  // alloc 20 because i think thats big enough
  char input[20];
  int operator;
  long int base_10;
  // alloc 100 because ditto
  char str[100] = {'\0'};

  printf("Input a value to be converted and a 0 or 1\nfor binary to hex or hex to binary respectively (number 0/1):\n");
  scanf("%s %d", input, &operator);
  switch (operator) {
    case 0:
      // use %X to format base_10 to base_16
      printf("%lX\n", strtol(input, NULL, 2));
      break;
    case 1:
      // throw into a buffer to convert base_10 long into str
      base_10 = strtol(input, NULL, 16);
      ltobs(base_10, str);

      // convert the decimal, then use strtol to truncate the excess leading digits. LOL.
      printf("%ld\n", strtol(str, NULL, 10));
      break;
    default:
      printf("Expected either 0 or 1, not %d", operator);
  }
}