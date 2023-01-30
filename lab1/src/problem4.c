#include <stdio.h>

// Yoink! https://stackoverflow.com/a/35583819/17954209
void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void rev(char* array, size_t n) {
    for (size_t i = 0; i < n / 2; i++)
        swap(array + i, array +(n - i - 1));
}

void rotate_one(char* str, int str_len) {
    rev(str + 1, str_len - 1);
    rev(str, str_len);
}

/*
Long int to binary string
*/
void ltobs(long int v, char *word) {
  long int temp_decimal;
  // ok dynamically malloc this to same as the hexadeciamal input length
  // to the amount of digits required by the same binary representation
  // would be the ideal. but respectfully, i don't get enough points from this lab
  // to learn how to do that.
  int binary_reverse[100] = { 0 };
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
  for (int j = 0; j < array_length; j++) {
    int reverse_index = array_length - 1 - j;
    // printf("%i, %i, %i\n", j, reverse_index, binary_reverse[reverse_index]);
    word[j] = binary_reverse[reverse_index]+'0'; // this should cast to char
    // printf("%c", word);
  }

  // array rotate forwards to remove leading zeros
  while (word[0] != '1') {
    word[0] = '\0';
    rotate_one(word, 100);
  }
}

/*
Prompts user input for a number and space seperated 0 or 1
for binary to hex or hex to binary respectively
*/
int main() {
  // alloc 100 because i think thats big enough
  char input[100];
  int operator;
  long int base_10;
  // alloc 100 because ditto
  char str[100] = {'\0'};

  printf("Input a value to be converted and a 0 or 1\nfor binary to hex or hex to binary respectively:\n");
  scanf("%s %d", input, &operator);
  switch (operator) {
    case 0:
      // converts from base2 to base10, then uses %lX to format as hexadecimal
      printf("%lX\n", strtol(input, NULL, 2));
      break;
    case 1:
      // convert from base16 to base10
      base_10 = strtol(input, NULL, 16);

      // convert from base10 to base2
      ltobs(base_10, str);

      printf("%s", str);
      break;
    default:
      printf("Expected either 0, 1, not %c", operator);
  }
}