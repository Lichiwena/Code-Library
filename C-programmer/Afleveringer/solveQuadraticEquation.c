#include <stdio.h>
#include <math.h>

void solveQuadraticEquation(double a, double b, double c);
double find_discriminant(double a, double b, double c);
double find_first_root(double discriminant, double a, double b);
double find_second_root(double discriminant, double a, double b);

int main(void)
{
    double a = 1.0,
           b = 1.0,
           c = 1.0;
    int    scanres;
    char   ch;

    /* Input validation: Tjekker for bogstavinput og at alle koefficienter ikke == 0. */
    do 
    {
        printf("Enter coeficients a, b, and c: ");
        scanres = scanf(" %lf %lf %lf", &a, &b, &c);
        if (scanres != 3)
        {
            do 
            {
                scanf("%c", &ch);
            }while (ch != '\n');
        }
    }while ((scanres != 3) || (a == 0 && b == 0 && c == 0));
    
    printf("The discriminant is: %.2f.\n", find_discriminant(a, b, c));

    solveQuadraticEquation(a, b, c);

  return (0);
}

/* En funktion, som løser en andengradsligning. */
void solveQuadraticEquation(double a, double b, double c)
{  
    find_first_root(find_discriminant(a, b, c), a, b);
    find_second_root(find_discriminant(a, b, c), a, b);
} 

/* En funktion, der udregner diskriminanten og returnerer dennes værdi. */
double find_discriminant(double a, double b, double c)
{
    double discriminant = 0;

    discriminant = b * b - 4 * a * c;

    return discriminant;
}

/* En funktion, der finder root1, hvis den eksisterer. Ellers printes "There are no roots" */
double find_first_root(double discriminant, double a, double b)
{
    double root1;

    if (discriminant < 0)
        printf("There are no roots.\n");

    else if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        printf("The first root is: %.2lf.\n", root1);
    }

    else /* Bliver kun udført, hvis discriminant == 0.*/
    {
        root1 = (-b) / (2 * a );
        printf("The only root is: %.2lf.\n", root1);
    }

    return root1;
}

/* En funktion, der finder root2, hvis den eksisterer (altså hvis discriminant>0). */
double find_second_root(double discriminant, double a, double b)
{
    double root2;

    if (discriminant > 0)
    {
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The second root is: %.2lf.\n", root2);
    }
    
    return root2;
}