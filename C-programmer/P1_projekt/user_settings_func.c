#include <stdlib.h> /* Standard library, brugt til random generator */
#include <stdio.h> /* Standard library, brugt til FILE */
#include <string.h> /* Standard library, brugt til string compare osv */
#include <time.h> /* Standard library, brugt til seed til random generator */
#include "main.h" /* Inkluderer main.h headerfilen */

void user_settings(FILE *usersettings){
    int vegan, vegetarian, pricerange_max, answer3 = 10;
    char answer1 = 'a', answer2 = 'b';
    
    while(answer1 != 'J' && answer1 != 'j' && answer1 != 'N' && answer1 != 'n'){
        printf("Er du veganer? J/N");
        scanf(" %c", &answer1);
        if(answer1 == 'J' || answer1 == 'j'){
            vegan = TRUE;
        }
        else if(answer1 == 'N' || answer1 == 'n'){
            vegan = FALSE;
        }
        fflush(stdin);
    }
    
    if(vegan == FALSE){
        while(answer2 != 'J' && answer2 != 'j' && answer2 != 'N' && answer2 != 'n'){
            printf("Er du vegetar? J/N");
            scanf("%c", &answer2);
            if(answer2 == 'J' || answer2 == 'j'){
            vegetarian = TRUE;
            }
            else if(answer2 == 'N' || answer2 == 'n'){
                vegetarian = FALSE;
        }
        fflush(stdin);
    }
    
    while(answer3 != 1 && answer3 != 2 && answer3 != 3 && answer3 != 4 && answer3 != 5){
        printf("Hvad er den maksimale prisklasse, du oensker? 1-5");
        scanf("%d", &answer3);
            if(answer3 == 1){
            pricerange_max = 1;
            }
            else if(answer3 == 2){
                pricerange_max = 2;
            }
            else if(answer3 == 3){
                pricerange_max = 3;
            }
            else if(answer3 == 4){
                pricerange_max = 4;
            }
            else if(answer3 == 5){
                pricerange_max = 5;
        }
    fflush(stdin);
    }

    fprintf(usersettings, "Veganer: %d\n", vegan);
    fprintf(usersettings, "Vegetar: %d\n", vegetarian);
    fprintf(usersettings, "Max prisklasse: %d\n", pricerange_max);
    }
}