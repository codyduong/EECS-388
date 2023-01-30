#include <stdio.h>


// Returns the index where the character is found, -1 if it is not found
int value_in(char *a, char v) {
  int i = 0;
  // use \0 instead of stroflen
  while (a[i] != '\0') {
    if (v == a[i]) {
      return i;
    }
    i++;
  }
  return -1;
}


void check_duplicates(char *a) {
  char duplicate[100] = {'\0'};
  int duplicate_count[100] = {0};

  int index = 0;
  int in_index = 0;
  int duplicate_index = 0;
  // use \0 instead of stroflen
  while (a[index] != '\0') {
    in_index = value_in(duplicate, a[index]);
    // printf("%d", in_index);
    if (in_index == -1) {
      duplicate[duplicate_index] = a[index];
      duplicate_index++;
    } else {
      duplicate_count[in_index]++;
    }
    index++;
  }

  // print our duplicates by just going thru the list
  printf("Duplicate characters:\n");
  int duplicate_char_index = 0;
  while (duplicate[duplicate_char_index] != '\0') {
    printf("%c has %d duplicate(s)\n", duplicate[duplicate_char_index], duplicate_count[duplicate_char_index]);
    duplicate_char_index++;
  }
}


int main() {
  char input[100];

  printf("Input a string to count for duplicate values:\n");
  scanf("%s", input);
  check_duplicates(input);
}