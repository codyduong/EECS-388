#include <stdio.h>
#include <math.h>



double calcuate(double n1, double n2, char o) {
  switch (o) {
    case '+':
      return n1+n2;
    case '-':
      return n1-n2;
    case '*':
      return n1*n2;
    case '/':
      return n1/n2;
    case '^':
      return pow(n1, n2);
    // Should these next three be here if they dont use n2? 
    // Probably not... w/e LOL.
    case 's':
      return sqrt(n1);
    case 'c':
      return ceil(n1);
    case 'f':
      return floor(n1);
    default:
      printf ("Invalid operator");
      return 0;
  }
}



int main () {
  double n1;
  double n2;
  char o;
  char o2 = '\0';
  double n3;
  
  int temp = 0;

  // the order is unorthodox but w/e. input validation is non-existent, so don't mess it up
  printf("Calculator Supported Operators\n");
  printf("  + Addition        - Subtraction\n");
  printf("  * Multiplication  / Division\n");
  printf("  ^ Power           s(n) Square Root\n");
  printf("  c(n) Ceiling      f(n) Floor\n");
  printf("  (a+b)^n Multi-step Solver\n\n");
  printf("Input equation: \n");
  

  // this is like a really shitty AST analyzer
  if (scanf ("%lf%c%lf", &n1, &o, &n2) != 3) {
    if (scanf ("%c(%lf)", &o, &n1) == 2) {
      // this gets the job done, even if makes the code structure is ugly as sin
      // either refactor all printf and calculations to be inside or outside, not both LOL
      printf("%c(%lf) = %lf", o, n1, calcuate(n1, n2, o));
      return 0;
    } else {
      scanf ("(%lf%c%lf)%c%lf", &n1, &o, &n2, &o2, &n3);
    }
  }

  if (o2 != '\0') {
    printf("(%lf%c%lf)%c%lf = %lf\n", n1, o, n2, o2, n3, calcuate(calcuate(n1, n2, o), n3, o2));
  } else {
    printf("%lf%c%lf = %lf\n", n1, o, n2, calcuate(n1, n2, o));
  }
}