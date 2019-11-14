#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void scan_data (char operator, double operand);
void do_next_op (char operator, double operand, double *accumulator);
double run_calculator (double accumulator, char operator, double operand);

int main(void)
{
    double accumulator = 0.0,
               operand = 0.0;
    char      operator = 'a';

    printf("Please enter an accumulator and an optional operant: ");

    run_calculator(accumulator, operator, operand); //Ikke sikker

return (0);

}

double run_calculator(double accumulator, char operator, double operand)
{
    scan_data(operator, operand);
    do_next_op(operator, operand, &accumulator);

    return accumulator; // Måske pointer
}

 void scan_data(char operator, double operand)
{
    scanf(" %c", &operator);

    if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^')
    {
        printf("Hej!\n");
        scanf(" %lf", &operand);
        printf("Operand is: %lf.\n", operand);
    }
}

/* Følgnede funktion behøver ikke returne noget, da man bruger pointere */
void do_next_op (char operator, double operand, double *accumulator)
{
    printf("Operator is again: %c. \n", operator);

    switch (operator)
    {
        case '+':
            *accumulator = *accumulator + operand;
            break;
        case '-':
            *accumulator = *accumulator - operand;
            break;
        case '*':
            *accumulator = *accumulator * operand;
            break;
        case '/':
            *accumulator = *accumulator / operand;
            break;
        case '^':
            *accumulator = pow(*accumulator, operand);       /* pow function found in math.h library */ 
            break;
        case '#':
            *accumulator = sqrt(*accumulator);
            break;
        case '%':
            *accumulator = *accumulator * (-1);
            break;
        case '!':
            *accumulator = 1 / *accumulator;
            break;
        default:
        printf("How did you get here?\n");
    }

}


