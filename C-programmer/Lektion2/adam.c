#include <stdio.h>

int main(void) {
    double m, n, side1, side2, hypotenuse;

    printf("Enter values for for m and n: ");
    scanf(" %lf %lf", &m, &n);

    side1 = (m * m) - (n * n);
    side2 = 2 * m * n;
    hypotenuse = (m * m) + (n * n);

    printf("Pythagorean triple: %.1f %.1f %.1f", side1, side2, hypotenuse);

    return 0; 
}