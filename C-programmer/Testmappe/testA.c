#include <stdio.h>

#define PI 3.141592653589793

int main(void)
{
   double radius;

   printf("Dette program beregner en cirkels radius.\n\n");

   printf("Indsaet radius:   ");
   scanf("%lf", &radius);

   printf("\nAreal = PI * radius * radius\n");
   printf("     = %.2f * %.2f * %.2f\n", PI, radius, radius);
   printf("     = %.5f\n", PI * radius * radius );

   return 0;
}
