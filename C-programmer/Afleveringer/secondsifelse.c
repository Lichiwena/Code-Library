#include <stdio.h>
   
#define SECONDS_PR_HOUR   3600    
#define SECONDS_PR_MINUTE   60    

int main(void)
{
    int       seconds_input = 0, 
               hours_result = 0,
             minutes_result = 0,
             seconds_result = 0,
        calculations_result = 0;

    while(seconds_input <= 0)       // Jeg starter mit while loop, så hvis brugeren taster en værdi, der er mindre end eller lig 0, så starter programmet forfra.
    {
        printf("Please enter the amount of seconds you would like converted: \n");
        scanf(" %d", &seconds_input); 

        hours_result = seconds_input / SECONDS_PR_HOUR;
        calculations_result = seconds_input % SECONDS_PR_HOUR; 

        minutes_result = calculations_result / SECONDS_PR_MINUTE;
        calculations_result = seconds_input % SECONDS_PR_MINUTE;

        seconds_result = calculations_result;

            /* Jeg laver min if statement med et betinget udtryk for at finde ud af, om der er flere end 0 sekunder.
            Herefter bruger jeg betinget udtryk til at finde ud af, om der skal stå second eller seconds. */

        if (seconds_input > 0)
        {
        printf(seconds_input == 1 ? "You entered %d second which is converted into " : "You entered %d seconds which is converted into ", seconds_input);
           
        break; // Mit while loop breaker hvis seconds_input > 0 og resten af programmet køres.

        } else {
            printf("You entered %d which is an invalid input. \n\n", seconds_input); // Error message ved seconds_input <= 0
        }
    }

    /* Jeg laver nu en sekvens af if for at finde ud af, om der er én eller flere af hhv. timer, minutter og sekunder.
    Derudover finder jeg ud af, om det skal stå i ental eller flertal ved brug af betingede udtryk, og får derefter printet , . eller &. */

    if (hours_result >= 1) 
    {
        printf(hours_result == 1 ? "%d hour" : "%d hours", hours_result);
        printf(minutes_result != 0 && seconds_result != 0 ? ", " : (minutes_result == 0 && seconds_result == 0 ? "." : " & "));
    }

    if (minutes_result >= 1)
    {
        printf(minutes_result == 1 ? "%d minute" : "%d minutes", minutes_result);
        printf(seconds_result != 0 ? " & " : ".");
    }

    if (seconds_result >=1)
    {
        printf(seconds_result == 1 ? "%d second." : "%d seconds.", seconds_result);
    }

    printf("\n");

    return (0);
}
