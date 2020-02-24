#include <stdlib.h> /* Standard library, brugt til random generator */
#include <stdio.h> /* Standard library, brugt til FILE */

void clear_screen();

int main(void)
{
	int r = 0;

	printf("%d Hello. This is the start of the program.\n", r);
	printf("r is: %d \n", r);

	clear_screen();

	r = system("cls");

	printf("r is now: %d \n", r);

	return 0;
}

void clear_screen(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}