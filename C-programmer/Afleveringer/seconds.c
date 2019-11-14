#include <stdio.h>

#define WEEKS 604800    // Her definerer jeg min variabel "WEEKS" i sekunder.
#define DAYS   86400    // Her definerer jeg min variabel "DAYS" i sekunder.
#define HOURS   3600    // Her definerer jeg min variabel "HOURS" i sekunder.
#define MINUTES   60    // Her definerer jeg min variabel "MINUTES" i sekunder.

int main(void)
{

int seconds = 0,        // Jeg definerer min INT variabel "seconds" og tilskriver den startværdien 0, så den ikke har en udefineret startværdi.
    a = 0,              // Jeg definerer nu resten af mine variabler "a", "b", "c", "d" og "e" og tilskriver samme startværdi som før; 0.
    b = 0,              
    c = 0,
    d = 0,
    e = 0,
    rest = 0,           // Jeg definerer min variabel "rest" med startværdien 0. Jeg indser hurtigt, at jeg kun behøver at lave én restvariabel, da "rest" alligevel bliver overskrevet, når jeg regner videre med % senere.
                        // Derfor er det mere efficient blot at lave én "rest" variabel, selvom man sagtens kunne lave flere og få programmet til at køre.
    answer = 1;         // Jeg definer her min variabel "answer" med startværdien 1.

while(answer == 1)      // Jeg starter mit while loop med condition "answer == 1". Den skal jeg senere bruge i linje 42. Den fik startværdi 1, da mit while loop ellers ikke ville køre.  
{
    printf("Hello! \nPlease enter the amount of seconds you would like converted: \n"); // Her beder jeg brugeren om at indtaste det antal sekunder, han/hun vil have beregnet.
    scanf(" %d", &seconds); // Her siger jeg til compileren, at den skal scanne brugerens input og indsætte det på variablen "seconds"'s plads.

    a = seconds / WEEKS;    // Nu beder jeg programmet om at beregne det heltal, der skal stå foran "WEEKS".
    rest = seconds % WEEKS; // Jeg finder resten mellem seconds og WEEKS ved brug af modulo operatoren. 

    b = rest / DAYS;        // Nu beder jeg programmet om at beregne det heltal, der skal stå foran "DAYS". Dette gøres ved at tage resten fra tidligere beregning og dividere med "DAYS".
    rest = seconds % DAYS;  // Jeg fortsætter på samme måde, til jeg er nået hele vejen igennem.

    c = rest / HOURS;
    rest = seconds % HOURS; 

    d = rest / MINUTES;
    rest = seconds % MINUTES;

    e = rest;               // Til sidst laver jeg min variabel e, som blot er "e = rest", da min rest nu er et heltal i sekunder.

    printf("The result is:\n%d Weeks %d Days %d Hours %d Minutes %d Seconds\n", a, b, c, d, e); //Her beder jeg compileren om at printe teksten "Weeks Days Hours Minutes Seconds" med de tidligere udregnede værdier.

    printf("\nWould you like to do another convertion?\nPress 1 for Yes and 2 for No \n"); //Her spørger jeg brugeren, om han/hun vil køre programmet igen.
    scanf(" %d", &answer);  // Jeg beder compileren om at scanne brugerens input, 1 eller 2.

    if (answer == 2)        // Hvis answer = 1, så køres programmet igen (da while loopet så køres igen)
    {                       
        break;              // Hvis answer = 2, så breaker mit while loop, og programmet afsluttes med næste printf besked.
    }                       // Her afsluttes mit if statement.
}                           // Her afsluttes mit while loop.

    printf("Thanks for trying out my program!\n"); 

return (0);
} 
