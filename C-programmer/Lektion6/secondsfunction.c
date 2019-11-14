#include <stdio.h>

#define SECONDS_PR_HOUR   3600    
#define SECONDS_PR_MINUTE   60    

void hours_minutes_seconds(int seconds_input, int* hours_result, int* minutes_result, int* seconds_result);

int main(void)
{
    int seconds_input,
        seconds_result,
        minutes_result,
        hours_result;   

    printf("Please enter the amount of seconds you would like converted: \n");
    scanf(" %d", &seconds_input); 

    hours_minutes_seconds(seconds_input, &hours_result, &minutes_result, &seconds_result);

    if (seconds_input > 0)
            {
            printf(seconds_input == 1 ? "You entered %d second which is converted into " : "You entered %d seconds which is converted into ", seconds_input);

            } else {
                printf("You entered %d which is an invalid input. \n\n", seconds_input); // Error message ved seconds_input <= 0
            }

                if (hours_result >= 1) 
            {
                printf(hours_result == 1 ? "%d hour" : "%d hours", hours_result);
                printf(minutes_result != 0 && seconds_result != 0 ? ", " : (minutes_result == 0 && seconds_result == 0 ? "." : " & "));
            }

            if (minutes_result >= 1)
            {
                printf(minutes_result == 1 ? "%d minute" : "%d minutes", minutes_result);
                printf(seconds_result != 0 ? " and " : ".");
            }

            if (seconds_result >=1)
            {
                printf(seconds_result == 1 ? "%d second." : "%d seconds.", seconds_result);
            }

        printf("\n");

    return (0);
}

void hours_minutes_seconds(int seconds_input, int* hours_result, int* minutes_result, int* seconds_result)
{
    int calculations_result1 = 0; 

        *hours_result = seconds_input / SECONDS_PR_HOUR;
        calculations_result1 = seconds_input % SECONDS_PR_HOUR; 

        *minutes_result = calculations_result1 / SECONDS_PR_MINUTE;
        *seconds_result = seconds_input % SECONDS_PR_MINUTE;      
}