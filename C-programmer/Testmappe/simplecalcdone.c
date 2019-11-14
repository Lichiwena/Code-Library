/* Navn: Sarah Mølleskov Frandsen   *
 * Email: sfrand19@student.aau.dk   *
 * Gruppe: DAT A311                 *
 * Studieretning: Datalogi          */

/* I hhv. linje 78 og 83 er der brugt funktioner fra math.h library. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void scan_data (char *operator, double *operand);
void do_next_op (char *operator, double *operand, double *accumulator);
void run_calculator (double *accumulator, char *operator, double *operand);

int main(void)
{
    double accumulator = 0.0,
               operand = 0.0;
    char      operator = 'a';

    printf("Please enter an operator and an optional operand: ");

    while (operator != 'q')
    {
        run_calculator(&accumulator, &operator, &operand);

        if (operator != 'q')
        {
            printf("Result so far is: %.4lf.\n", accumulator);
        }
    }

    printf("Final result is: %.4lf. \n", accumulator);

    return (0);
}

/* Følgende funktion kalder de to funktioner scan_data og do_next_op. */
void run_calculator(double *accumulator, char *operator, double *operand)
{
    scan_data(operator, operand);
    do_next_op(operator, operand, accumulator);
}

/* Følgende funktion scanner efter operator og operant. Den scanner kun efter en operand, hvis det er nødvendigt, altså hvis der er brugt en binær operator. */
void scan_data(char *operator, double *operand)
{
    scanf(" %c", operator);

    if (*operator == '+' || *operator == '-' || *operator == '*' || *operator == '/' || *operator == '^')
    {
        scanf(" %lf", operand);
    }
}

/* Følgende funktion switcher på operatoren og ændrer herefter accumulatorens værdi tilsvarende. */
void do_next_op (char *operator, double *operand, double *accumulator)
{
    switch (*operator)
    {
        case '+':
            *accumulator = *accumulator + *operand;
            break;
        case '-':
            *accumulator = *accumulator - *operand;
            break;
        case '*':
            *accumulator = *accumulator * *operand;
            break;
        case '/':
            if (*operand != 0)
            {
                *accumulator = *accumulator / *operand;
            }
            break;
        case '^':
            *accumulator = pow(*accumulator, *operand);       
            break;
        case '#':
            if (*accumulator > 0)
            {
                *accumulator = sqrt(*accumulator);
            }
            break;
        case '%':
            *accumulator = *accumulator * (-1);
            break;
        case '!':
            *accumulator = 1 / *accumulator;
            break;
        case 'q': 
            break;
    }
}