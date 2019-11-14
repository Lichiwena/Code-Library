#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIE_EYE_MAX 6
#define RAND_MIN 1

int roll_multiple_dies(int n);

int main(void)
{
    int n = 0,
        i = 0;

    /* Random number generator funktion fra time.h */
    srand(time(NULL));

    printf("Please enter number of dies n, where n > 1:\n");
    scanf( "%d", &n);
    printf("Your input n is: %d. \n", n);

    for (int i = 0; i < 10; ++i)
    {
        printf("The dies show: %d.\n", roll_multiple_dies());
    }

/*
for (int i = 0; i < n; ++i)
    {
        pointer[i] = rand(); 

        printf("Pointer[%d]: %.2lf.\n", i, pointer[i]);
    }
*/

return(0);
}

int roll_multiple_dies(int n)
{
    int i = 0;

    for (int i = 0; i < *n; ++i)
    {
        rand() % DIE_EYE_MAX + 1;
        printf("Jeg kommer ind i roll_multiple_dies for løkke\n");
    }  

    return
}
