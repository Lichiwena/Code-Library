#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int element_compare(const void *ip1, const void *ip2);

int main(void)
{
    double n = 100;
    double *pointer = 0;
    int i = 0;

    /* Random number generator funktion fra time.h */
    srand(time(NULL));

    pointer = (double*)malloc(n*sizeof(double));

    /* Tjekker om allokeringen ved brug af malloc blev gennemført. */
    if (*malloc == 0)
    {
        printf("Allokeringen blev ikke gennemført. \n");
    }
    else {
        printf("Allokeringen blev gennemført.\n");
    }
       printf("\nNumbers, unsorted:\n");

       /* Laver et array med 100 (0-99) elementer, som derefter får assignet
       et random tal fra srand funktionen. Dette gøres, indtil i ikke er
       mindre end n = 100. Printer herefter indekstallet i arrayet og dets
       dertilhørende random generated tal. */
        for (int i = 0; i < n; ++i)
        {
            pointer[i] = rand(); 

            printf("Pointer[%d]: %.2lf.\n", i, pointer[i]);
        }

        printf("\n\nSorted numbers, smallest number to highest number:\n");

        qsort(pointer, n, sizeof(double), element_compare);

        for (int i = 0; i < n; ++i)
        {
            printf("Pointer[%d]: %.2lf.\n", i, pointer[i]);
        }

    return (0);
}


/* Nakket fra Kurt. qsort bruger result, men det skal ikke printes. */
int element_compare(const void *ip1, const void *ip2)
{
    int result;
    double *ipi1 = (double *)ip1,         /* Cast parameters to pointers to int */
        *ipi2 = (double *)ip2;

    if (*ipi1 < *ipi2)
        result = -1;
    else if (*ipi1 > *ipi2)
        result = 1;
    else
        result = 0;

    return result;
}