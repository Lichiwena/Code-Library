#include <stdio.h>

int main(void)
{

    int n = 0,
        calc = 0,
        dump = 0;

printf("Please enter a postive interger n: ");
scanf(" %d", &n);

for (calc = 0; calc <= n; ++calc)
{
    dump = calc + dump;
}

printf("The sum is %d.\n", dump);

if (dump == (n * (n + 1) / 2))
{
    printf("The sum and the calculation are equal.\n");
}

return(0);

}