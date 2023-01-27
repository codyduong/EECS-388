#include <stdio.h>

int main () {
  float n1;
  float n2;
  char o;
  int temp = 0;

  // the order is unorthodox but w/e. input validation is non-existent, so don't mess it up
  printf("Calculator: Type an operand operator operand (space-seperated 'n1 o n2'): \n");
  scanf ("%f %c %f", &n1, &o, &n2);
  // use case-switch to calculate, default to invalid input
  switch (o)
    {
    case '+':
      printf ("The sum of %f and %f is %f", n1, n2, n1+n2);
      break;
    case '-':
      printf ("The difference of %f and %f is %f ", n1, n2, n1-n2);
      break;
    case '*':
      printf ("The multiple of %f and %f is %f", n1, n2, n1*n2);
      break;
    case '/':
      printf ("The quotient of %f and %f is %f", n1, n2, n1/n2);
      break;
    default:
      printf ("Invalid input, expected operator to be one of ['-', '+', '/', '*']");
      return 1;
      break;
    }
}