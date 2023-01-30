#include <stdio.h>


int strtolen(char* s) {
  int i = 0;
  // ++i is actually a neat syntax from the lectures. 
  // Really saves on the 2 lines I replaced with this comment instead
  while (s[++i] != '\0') {}
  return i;
}


void main() {
  char input[100];

  printf("Input a string to check its length:\n");
  scanf("%s", input);
  printf("%d\n", strtolen(input));
}