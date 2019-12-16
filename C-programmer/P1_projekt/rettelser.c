#include <stdlib.h> /* Standard library, brugt til random generator */
#include <stdio.h> /* Standard library, brugt til FILE */
#include <string.h> /* Standard library, brugt til string compare osv */
#include <time.h> /* Standard library, brugt til seed til random generator */
#include <conio.h> /* Standard library, brugt til system kommandoer*/
#include "main.h" /* Inkluderer main.h headerfilen */
#include "error.h" /*Inkluderer error.h headerfilen */

/*Menu til brugeren kan vaelge funktioner*/
void menu(FILE *psettingsFile, int numberOfRecipes){
    FILE *poutFile = fopen("madplan.txt", "w"); /*Laver inputfilen*/
    int userInput = 0, checkValue = 0, randomValue[7], tempValue[7], weekdayIndex = 0, ingredientsIndex = 0;
   
    printf("################################################################\n");
    printf("## Velkommen til den digitale madplan                         ##\n");
    printf("## Hvad kunne du taenke dig at goere? Tast et tal fra 1 til 3 ##\n");
    printf("## Tast '1' for at udskrive en madplan                        ##\n"); 
    printf("## Tast '2' for at aendre indstillinger                       ##\n");
    printf("## Tast '3' for at lukke programmet                           ##\n");
    printf("################################################################\n");
    scanf("%d", &userInput);
    if (userInput == 1){
        clear_screen();
        for (checkValue = 0; checkValue < 7;)
        {
            randomValue[checkValue] = rand() % (numberOfRecipes - 1);
            if ((randomValue[checkValue] != tempValue[checkValue]) && (randomValue[checkValue] != tempValue[checkValue + 1]) && (randomValue[checkValue] != tempValue[checkValue + 2]) &&
                (randomValue[checkValue] != tempValue[checkValue + 3]) && (randomValue[checkValue] != tempValue[checkValue + 4]) && (randomValue[checkValue] != tempValue[checkValue + 5]) &&
                (randomValue[checkValue] != tempValue[checkValue + 6]))
            {
                print_meal_plan(poutFile, weekdayIndex, randomValue[weekdayIndex], numberOfRecipes);
                make_ingredients(randomValue[weekdayIndex], ingredientsIndex);
                checkValue++;
                weekdayIndex++;
            }
            tempValue[checkValue] = randomValue[checkValue];
            ingredientsIndex++;
        }
        satisfied_with_mealplan(poutFile, numberOfRecipes);
        fclose(poutFile);
    }
    else if (userInput == 2){
        clear_screen();
        psettingsFile = fopen("settings.txt", "w");
        user_settings(psettingsFile, numberOfRecipes);
        fclose(psettingsFile);
        fopen("settings.txt", "r");
    }
    else if (userInput == 3){
        clear_screen();
        EXIT_SUCCESS;
    }
    else{
        error(1);
        menu(psettingsFile, numberOfRecipes);
    }
}


/*Printer en vegansk madplan*/
void print_vegan_meal_plan(FILE *output, int weekdayIndex, int databaseIndex, int numberOfRecipes){
    char weekdays[7][10] = {"Mandag", "Tirsdag", "Onsdag", "Torsdag", "Fredag", "Loerdag", "Soendag"};
    int i = 0;
    int *vegan_array = 0;

    vegan_array = calloc(numberOfRecipes, sizeof(int));

    if ((weekdays[weekdayIndex] == weekdays[1]) || (weekdays[weekdayIndex] == weekdays[3])
         || (weekdays[weekdayIndex] == weekdays[5]) || (weekdays[weekdayIndex] == weekdays[6])){
        fprintf(output, "###############################################################\n");
        fprintf(output, "########################### %s ###########################\n", weekdays[weekdayIndex]);
        printf("###############################################################\n");
        printf("########################### %s ###########################\n", weekdays[weekdayIndex]);
    }
    else{
        fprintf(output, "###############################################################\n");
        fprintf(output, "########################### %s ############################\n", weekdays[weekdayIndex]);
        printf("###############################################################\n");
        printf("########################### %s ############################\n", weekdays[weekdayIndex]);
    }

    for (i = 0; i < numberOfRecipes; ++i){
        if (database.vegan[i] == TRUE){
            vegan_array[i] = database.indexNumber[i];

            printf("%s\n", database.title[vegan_array[i]]);
            fprintf(output, "%s\n", database.title[vegan_array[i]]);
            printf("%s\n", database.description[vegan_array[i]]);
            fprintf(output, "%s\n", database.description[vegan_array[i]]);
            printf("%s\n", database.ingredients[vegan_array[i]]);
            fprintf(output, "%s\n", database.ingredients[vegan_array[i]]);
            fprintf(output, "Denne ret er vegetarisk\n");
            printf("Denne ret er vegetarisk\n");
            printf("Prisklasse: %d\n", database.price[vegan_array[i]]);
            fprintf(output, "Prisklasse: %d\n", database.price[vegan_array[i]]);
            printf("Tid: %d minutter\n", database.time[vegan_array[i]]);
            fprintf(output, "Tid: %d minutter\n", database.time[vegan_array[i]]);
            
            database.indexNumber[i]++;
            i = numberOfRecipes;
        }
    }
    
    free(vegan_array);
}


/*Funktion til at lave madplan filen*/
void print_standard_meal_plan(FILE *output, int weekdayIndex, int databaseIndex){
    char weekdays[7][10] = {"Mandag", "Tirsdag", "Onsdag", "Torsdag", "Fredag", "Loerdag", "Soendag"};
    
    /* Hvis weekdays[weekdayIndex] er Tirs, Tors, Loer el. Soen saa skal den printe et # mindre, */
    /* fordi disse dage er ét tegn laengere end resten af ugens dage, saa det ser paent ud.     */
    if ((weekdays[weekdayIndex] == weekdays[1]) || (weekdays[weekdayIndex] == weekdays[3])
         || (weekdays[weekdayIndex] == weekdays[5]) || (weekdays[weekdayIndex] == weekdays[6])){
        fprintf(output, "###############################################################\n");
        fprintf(output, "########################### %s ###########################\n", weekdays[weekdayIndex]);
        printf("###############################################################\n");
        printf("########################### %s ###########################\n", weekdays[weekdayIndex]);
    }
    else{
        fprintf(output, "###############################################################\n");
        fprintf(output, "########################### %s ############################\n", weekdays[weekdayIndex]);
        printf("###############################################################\n");
        printf("########################### %s ############################\n", weekdays[weekdayIndex]);
    }
    fprintf(output, "%s\n", database.title[databaseIndex]);
    fprintf(output, "%s\n", database.description[databaseIndex]);
    fprintf(output, "%s\n", database.ingredients[databaseIndex]);
    printf("%s\n", database.title[databaseIndex]);

    if (database.vegetarian[databaseIndex] == FALSE){
        fprintf(output, "Denne ret er ikke vegetarisk\n");
    }
    else{
        fprintf(output, "Denne ret er vegetarisk\n");
    }
    if (database.vegan[databaseIndex] == FALSE){
        fprintf(output, "Denne ret er ikke vegansk\n");
    }
    else{
        fprintf(output, "Denne ret er vegansk\n");
    }
    fprintf(output, "Prisklasse: %d\n", database.price[databaseIndex]);
    fprintf(output, "Tid: %d minutter\n", database.time[databaseIndex]);
    printf("Prisklasse: %d\n", database.price[databaseIndex]);
    printf("Tid: %d minutter\n", database.time[databaseIndex]);
}

/*Spoerger brugeren om vedkommende er tilfreds*/
int satisfied_with_mealplan(FILE *output, int numberOfRecipes){
    char krit1[255], krit2[255], satisfied;
    int newRandomIndex = -1, weekday;
    srand(time(NULL));

    printf("\nFlere informationer om madplanen findes i madplan.txt-filen, blandt andet opskrifter.\n");
    printf("Er du tilfreds med din madplan? J/N \n");
    scanf(" %c", &satisfied);

    if (satisfied == 'N' || satisfied == 'n'){
        printf("\n Du har valgt, at du ikke er tilfreds. \nHvilken dag er du ikke tilfreds med? (Indtast nummer paa dagen)\n");
        scanf(" %d", &weekday);

        while (newRandomIndex == -1){
            printf("Hvilke ingredienser oensker du at inddrage i opskriften? Indtast to:\n");
            scanf(" %s %s", krit1, krit2);
            newRandomIndex = find_new_dish(krit1, krit2, numberOfRecipes);
            if (newRandomIndex == -1){
                error(1);
            }
        }
        weekday -= 1;
        print_meal_plan(output, weekday, newRandomIndex, numberOfRecipes);
    }
    return 0;
}

/* Denne funktion clearer terminalen. */
void clear_screen()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}