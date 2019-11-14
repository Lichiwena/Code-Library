#include <stdio.h>

int sum_iter (int n);
int sum_formula (int n, int dump);

int main(void)
{
    int input = 0,
        dump = 0;

printf("Please enter a postive interger: ");
scanf(" %d", &input);

dump = sum_iter(input);

printf("The sum of all intergers from 1 until %d is %d.\n\n", input, dump);

sum_formula(input, dump);

return (0);
}

int sum_iter (int n)
{
    int dump = 0,
        calc = 0;

    for (calc = 0; calc <= n; ++calc)
    {
        dump = calc + dump;
    }
  
    return dump; 
}

int sum_formula(int n, int dump)
{

    if (dump == (n * (n + 1) / 2))
    {
        printf("The sum and the calculation are equal.\n");
    }

}
