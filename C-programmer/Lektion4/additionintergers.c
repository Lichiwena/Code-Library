#include <stdio.h>

int main(void)
{

int n = 0,
	m = 0,
	k = 0,
	i = 0,
	sum = 0;

printf("Please enter three positive intergers n, m and k:\n");
scanf(" %d %d %d", &n, &m, &k);

printf("You entered %d and %d and %d.\n", n, m, k);

for (i = n; i <= m; i++)
{
	if ((i % k) == 0) // Hvis i % k ikke har en rest, saa gemmer vi tallet i sum.
	{
		sum = sum + i;
	}
}
	printf("Result is: %d\n.", sum);

return(0);
}