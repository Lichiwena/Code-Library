#include <stdio.h>
#include <stdlib.h>

void dollars_converter(double input_dollars, double* euros, double* danish_krone, double* rubies, double* yen);

int main(void)
{
    double input_dollars;
    double euros;
    double danish_krone;
    double rubies;
    double yen;
    
    printf("Please enter input in dollars you'd like calculated: \n");
    scanf(" %lf", &input_dollars);

    do{
        dollars_converter(input_dollars, &euros, &danish_krone, &rubies, &yen);

        printf("%0.2f dollar(s) is equal to %0.2f EUR, %0.2f DKK, %0.2f INR and %0.2f JPY.\n", input_dollars, euros, danish_krone, rubies, yen);
        input_dollars++;
    }
    while(input_dollars <= 100);

return(0);
}

void dollars_converter(double input_dollars, double* euros, double* danish_krone, double* rubies, double* yen)
{
    *euros = (input_dollars * 0.89);
    *danish_krone = (input_dollars * 6.66);
    *rubies = (input_dollars * 66.43);
    *yen = (input_dollars * 119.9);
}

