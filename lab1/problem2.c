#include <stdio.h>

void main () {
  /*
  queries for user input height, then just prints out based on
  different height values
  */
  float height;

  printf("Input height (in cm):\n");
  scanf("%f", &height);

  if (height >= 180) {
    printf("You are tall");
  } else if (height <= 150) {
    printf("You are short");
  } else {
    printf("You are medium");
  }
}