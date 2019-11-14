#include <stdio.h>

int main(void) {

  double d, e, f;

  printf("Enter three real numbers: ");
  scanf("%lf %lf %lf", &d, &e, &f);
  
  printf("The average is: %lf\n", (d + e + f) / 3.0);
    
  return 0;
}
/* Jeg inputter 1 2 3. Jeg får "The average is: -1344973483"
   Jeg retter %d i linje 10 til %lf, da variablerne er defineret med en double.
   Derudover retter jeg %d %d %d i linje 8 til %lf %lf %lf - igen, da vi har
   med en double at gøre.

*/