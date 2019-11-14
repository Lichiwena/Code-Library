#include <stdio.h>

int main(void) {

	int i, j, small, large, remainder;
	
	printf("Enter two non-negative integers: ");
	scanf("%d %d", &i, &j);

	small = i <= j ? i : j; /* Hvad sker der hvis vi ikke sorterer*/
	large = i <= j ? j : i; /* i og j i disse to assignments */

	while (small > 0){
		remainder = large % small;
		large = small;
		small = remainder;
	}

printf("GCD of %d and %d is %d\n\n", i, j, large);

return 0;

}