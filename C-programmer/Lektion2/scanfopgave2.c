/* Her er næste version af programmet, som indlæser heltal:
*/

#include <stdio.h>

int main(void) {

  int i1, i2,
      scanRes; /* = Betyder, hvor mange af variablerne, den kan læse korrekt.
      				Eks scanRes = 2 betyder, den kan læse 2 variabler korrekt.
      				*/

  printf("Enter input on the following line\n");

  scanRes = scanf("%d%d", &i1, &i2);

  printf("i1 = %d, i2 = %d\n", i1, i2);
  printf("scanRes = %d\n", scanRes);

  return 0;
}

/* Opgave 1: Her får jeg i1 = 123 og i2 = 456, scanRes = 2. Dvs. den har læst
"123" som værdien af variabel i1 og "456" som værdien af vriablen i2.

   Opgave 2: - samme

   Opgave 3: Den kan kun læse en af variablerne korrekt, når man indsætter
   "123.456". Dette er grundet punktummet, derfor sætter den variabel i2 = 0.
*/
