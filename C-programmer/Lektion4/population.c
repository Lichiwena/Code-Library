#include <stdio.h>

int main(void)
{

int population = 9870,
	count_years = 0;

while(population <= 30000)
{
	printf("Years from start: %d\n", count_years);
	printf("Population status: %d\n", population);
	population = population * 1.10;
	count_years = ++count_years;
}
	
printf("It takes %d years before the population surpasses 30 000\n", count_years);

return (0);
}