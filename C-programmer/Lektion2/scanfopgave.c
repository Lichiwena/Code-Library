#include <stdio.h>

int main(void) {

  int c1, c2, c3, c4,   scanRes;

  printf("Enter input on the following line\n");

  scanRes = scanf("%c%c%c%c", &c1, &c2, &c3, &c4); 

  /* = Betyder, hvor mange af variablerne, den kan læse korrekt.
                    Eks scanRes = 2 betyder, den kan læse 2 variabler korrekt.
                    */

  printf("c1 = %c, c2 = %c, c3 = %c, c4 = %c\n", c1, c2, c3, c4);
  printf("scanRes = %d\n", scanRes);

  return 0;
}