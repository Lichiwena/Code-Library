#include <stdio.h>
#include <math.h>

int main(void)
{

double r = 0,
       x = 0,
       y = 0,
       distance = 0;

printf("Indtast en radius og et punkt paa formen x y:\n");
scanf(" %lf %lf %lf", &r, &x, &y);

distance = sqrt(pow(y-0,2)+pow(x-0,2));

printf( distance == 0 ? "On perimeter\n" : (distance > r ? "Outside perimeter\n" : "Inside perimiter\n"));

    return 0;
}