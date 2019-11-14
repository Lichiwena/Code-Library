#include <stdio.h>

#define SECONDS_PR_WEEK 604800    // Her definerer jeg mine variabler i sekunder.
#define SECONDS_PR_DAY   86400    
#define SECONDS_PR_HOUR   3600    
#define SECONDS_PR_MINUTE   60    

int main(void)
{

    int seconds = 0,        // Jeg definerer mine INT variabler og tilskriver dem en startværdi 0, så den ikke har en udefineret startværdi.
        weeks_result = 0,              
        days_result = 0,              
        hours_result = 0,
        minutes_result = 0,
        seconds_result = 0,
        rest = 0,           // Jeg definerer min variabel "rest" med startværdien 0. Jeg indser hurtigt, at jeg kun behøver at lave én restvariabel, da "rest" alligevel bliver overskrevet, når jeg regner videre med % senere.
        answer = 1;         // Jeg definer her min variabel "answer" med startværdien 1.

        while(answer == 1)      // Jeg starter mit while loop med condition "answer == 1". Den skal jeg senere bruge i linje 42. Den fik startværdi 1, da mit while loop ellers ikke ville køre.  
        {
            printf("Hello! \nPlease enter the amount of seconds you would like converted: \n");
            scanf(" %d", &seconds); 

            weeks_result = seconds / SECONDS_PR_WEEK;    // Nu beder jeg programmet om at beregne det heltal, der skal stå foran "WEEKS".
            rest = seconds % SECONDS_PR_WEEK;            // Jeg finder resten mellem seconds og WEEKS ved brug af modulo operatoren. 

            days_result = rest / SECONDS_PR_DAY;         // Nu beder jeg programmet om at beregne det heltal, der skal stå foran "DAYS". Dette gøres ved at tage resten fra tidligere beregning og dividere med "DAYS".
            rest = seconds % SECONDS_PR_DAY;             // Jeg fortsætter på samme måde, til jeg er nået hele vejen igennem.

            hours_result = rest / SECONDS_PR_HOUR;
            rest = seconds % SECONDS_PR_HOUR; 

            minutes_result = rest / SECONDS_PR_MINUTE;
            rest = seconds % SECONDS_PR_MINUTE;

            seconds_result = rest;                        // Til sidst laver jeg min variabel e, som blot er "e = rest", da min rest nu er et heltal i sekunder.

            printf("The result is:\n%d Weeks %d Days %d Hours %d Minutes %d Seconds\n", weeks_result, days_result, hours_result, minutes_result, seconds_result);

            printf("\nWould you like to do another convertion?\nPress 1 for Yes and 2 for No \n");
            scanf(" %c", &answer);

            if (answer == 2)        // Hvis answer = 1, så køres programmet igen (da while loopet så køres igen)
            {                       
                break;              // Hvis answer = 2, så breaker mit while loop, og programmet afsluttes med næste printf besked.
        }
}

printf("Thanks for trying out my program!\n"); 

return (0);
} 
