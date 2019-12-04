#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_ugeplan(void);
void print_ugeplan_string(void);

int main(void)
{
    print_ugeplan();

return (0);
}

void print_ugeplan(void)
{
    printf("######################################################\n");
    printf("## Mandag:  Pasta og koedsovs \n");
    printf("######################################################\n");
    printf("## Tirsdag: Rugbroed med fiskefilet \n");
    printf("######################################################\n");
    printf("## Onsdag:  Mexicanske pandekager \n");
    printf("######################################################\n");
    printf("## Torsdag: Kartoffeltaerte \n");
    printf("######################################################\n");
    printf("## Fredag:  Forloren hare \n");
    printf("######################################################\n");
    printf("## Loerdag: Karry med ris \n");
    printf("######################################################\n");
    printf("## Soendag: Tarteletter \n");
    printf("######################################################\n");
}

/* Denne skal bruges, hvor man så printer den string (titel), */
/* der hører til den ret man vil printe.                      */
void print_ugeplan_string(void)
{
    printf("######################################################\n");
    printf("## Mandag:  %s \n", );
    printf("######################################################\n");
    printf("## Tirsdag: %s \n", );
    printf("######################################################\n");
    printf("## Onsdag:  %s \n", );
    printf("######################################################\n");
    printf("## Torsdag: %s \n", );
    printf("######################################################\n");
    printf("## Fredag:  %s \n", );
    printf("######################################################\n");
    printf("## Loerdag: %s \n", );
    printf("######################################################\n");
    printf("## Soendag: %s \n", );
    printf("######################################################\n");
}