#include <stdio.h>
#include <stdlib.h>

void bill_converter(int *input_dollars, int *number_of_100s, int *number_of_50s, int *number_of_20s, int *number_of_10s);

int main(void)
{
	int input_dollars,
		number_of_100s = 0,
		number_of_50s = 0,
		number_of_20s = 0,
		number_of_10s = 0;

	printf("Please enter the amount of dollars you would like issued: ", input_dollars);
	scanf(" %d", &input_dollars);

	if ((input_dollars % 10) == 0);
	{
		bill_converter(&input_dollars, &number_of_100s, &number_of_50s, &number_of_20s, &number_of_10s);
	
		printf("Number of 100s: %d.\nNumber of 50s: %d.\nNumber of 20s: %d.\nNumber of 10s: %d.\nThank you please come again.\n", number_of_100s, number_of_50s, number_of_20s, number_of_10s);

	} if ((input_dollars % 10) != 0) {
		printf("Please enter a number that can be divided by 10.\n");
	}

return(0);

}

void bill_converter(int *input_dollars, int *number_of_100s, int *number_of_50s, int *number_of_20s, int *number_of_10s)
{
	int calculation_result = 0;

	*number_of_100s = *input_dollars / 100;
	calculation_result = *input_dollars % 100;

	*number_of_50s = calculation_result / 50;
	calculation_result = calculation_result % 50;

	*number_of_20s = calculation_result / 20;
	calculation_result = calculation_result % 20;

	*number_of_10s = calculation_result / 10;
	calculation_result = calculation_result % 10;
}