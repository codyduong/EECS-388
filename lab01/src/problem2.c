#include <stdio.h>

int main () {
  /*
  queries for user input height, then just prints out based on
  different height values
  */
  float height;

  printf("Input height (in cm):\n");
  scanf("%f", &height);

  if (height >= 180) {
    /* above ~5'11" */
    printf("You are tall");
  } else if (height <= 150) {
    /* below ~4'11" */
    printf("You are short");
  } else {
    printf("You are medium");
  }
}