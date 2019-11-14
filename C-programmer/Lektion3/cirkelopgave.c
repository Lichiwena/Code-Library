#include <stdio.h>
#include <math.h>

int main(void)
{

	double r = 0,
       	   x = 0,
           y = 0,
           distance = 0;

	printf("Please enter a radius and a coordinate x y:\n");
	scanf(" %lf %lf %lf", &r, &x, &y);

	distance = sqrt(pow(y-0,2)+pow(x-0,2)); // Jeg beregner min double distance, så jeg finder ud af, om punktet ligger på, uden for eller inden for periferien.

	printf( distance == 0 ? "On perimeter\n" : (distance > r ? "Outside perimeter\n" : "Inside perimiter\n"));
	// Jeg vil lave en printf med et betinget udtryk, med endnu et betinget udtryk indeni.

    return 0;
}
