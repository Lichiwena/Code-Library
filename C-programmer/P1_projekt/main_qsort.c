#include <stdlib.h> /* Standard library, brugt til random generator */
#include <stdio.h> /* Standard library, brugt til FILE */
#include <string.h> /* Standard library, brugt til string compare osv */
#include <time.h> /* Standard library, brugt til seed til random generator */
#include "main.h" /* Inkluderer main.h headerfilen */

/*Første funktion der bliver kaldt*/
int main(void){
    FILE *pinputFile = fopen("data.txt", "r"); /*Finder inputfilen*/
    FILE *poutFile = fopen("madplan.txt", "w"); /*Laver inputfilen*/
    FILE *psettingsFile = fopen("settings.txt", "r");
    int checkForEOF = getc(pinputFile); /*læser første linje af inputfilen og sætter den checkForEOF til 1 hvis den kan læse en linje*/
    int databaseIndex = 0, weekdayIndex = 0, ingredientsIndex = 0, checkValue = 0, randomValue[7], tempValue[7];
    srand(time(NULL));

    if (psettingsFile == NULL)
    {
        psettingsFile = fopen("settings.txt", "w");
        user_settings(psettingsFile);
        fclose(psettingsFile);
        psettingsFile = fopen("settings.txt", "r");
        read_settings(psettingsFile);
    }
    else
    {
        read_settings(psettingsFile);
    }
    
    while (checkForEOF != EOF) /*Imens at den kan læse en linje kører dette*/
    {
        read_data(pinputFile, databaseIndex);
        databaseIndex++;
        checkForEOF = getc(pinputFile); /*Opdatere variablen*/
    }
    for (checkValue = 0; checkValue < 7;)
    {
        randomValue[checkValue] = rand() % 21;
        if ((randomValue[checkValue] != tempValue[checkValue]) && (randomValue[checkValue] != tempValue[checkValue+1]) && (randomValue[checkValue] != tempValue[checkValue+2]) && 
        (randomValue[checkValue] != tempValue[checkValue+3]) && (randomValue[checkValue] != tempValue[checkValue+4]) && (randomValue[checkValue] != tempValue[checkValue+5]) && 
        (randomValue[checkValue] != tempValue[checkValue+6]))
        {
            print_meal_plan(poutFile, weekdayIndex, randomValue[weekdayIndex]);
            make_ingredients(randomValue[weekdayIndex], ingredientsIndex);
            checkValue++;
            weekdayIndex++;
        }
        tempValue[checkValue] = randomValue[checkValue];
        ingredientsIndex++;
    }

    fclose(pinputFile);
    fclose(poutFile);

    return 0;
}

void user_settings(FILE *usersettings){
    int vegan, vegetarian, pricerange_max, answer3 = 0;
    char answer1 = 'a', answer2 = 'b';
    while (answer1 != 'J' && answer1 != 'j' && answer1 != 'N' && answer1 != 'n')
    {
        printf("Er du veganer? J/N ");
        scanf(" %c", &answer1);
        if (answer1 == 'J' || answer1 == 'j')
        {
            vegan = 1;
        }
        else if (answer1 == 'N' || answer1 == 'n')
        {
            vegan = 0;
        }
        fflush(stdin);
    }
    if (vegan == FALSE)
    {
        while (answer2 != 'J' && answer2 != 'j' && answer2 != 'N' && answer2 != 'n')
        {
            printf("Er du vegetar? J/N ");
            scanf("%c", &answer2);
            if (answer2 == 'J' || answer2 == 'j')
            {
                vegetarian = 1;
            }
            else if (answer2 == 'N' || answer2 == 'n')
            {
                vegetarian = 0;
            }
            fflush(stdin);
        }
    }

    while (answer3 != 1 && answer3 != 2 && answer3 != 3 && answer3 != 4 && answer3 != 5)
    {
        printf("Hvilken prisklasse vil du max have? 1-5 ");
        scanf("%d", &answer3);
        if (answer3 == 1)
        {
            pricerange_max = 1;
        }
        else if (answer3 == 2)
        {
            pricerange_max = 2;
        }
        else if (answer3 == 3)
        {
            pricerange_max = 3;
        }
        else if (answer3 == 4)
        {
            pricerange_max = 4;
        }
        else if (answer3 == 5)
        {
            pricerange_max = 5;
        }
        fflush(stdin);
    }
    fprintf(usersettings, "V %d\n", vegan);
    fprintf(usersettings, "V %d\n", vegetarian);
    fprintf(usersettings, "P %d\n", pricerange_max);
}

void read_settings(FILE *psettingsFile){
    fscanf(psettingsFile, "%*c %d %*c %d %*c %d", &settings.vegan, &settings.vegetarian, &settings.price);
    printf("%d, %d, %d\n", settings.vegan, settings.vegetarian, settings.price);
}

/*Funktion til at læse databasen og gemme det forskellige ting i variabler*/
void read_data(FILE *input, int databaseIndex){
    if (input == NULL)
    {
        printf("Filen findes ikke");
    }
    /*"%" med "*" betyder at den skal læse det men ikke gemme det*/
    fscanf(input, "%*[^=]= %d %*[^']' %[^']' %*[^']' %[^']' %*[^']' %[^']'  %*[^=]= %d %*[^=]= %d %*[^=]= %d %*[^=]= %d", &database.indexNumber[databaseIndex], database.title[databaseIndex], 
    database.description[databaseIndex], database.ingredients[databaseIndex], &database.vegetarian[databaseIndex], &database.vegan[databaseIndex], &database.price[databaseIndex], &database.time[databaseIndex]);
}

/*Funktion til at "lave" ingridenser*/
void make_ingredients(int databaseIndex, int ingredientsIndex){
    ingredients newIngriends[MAX_ARRAY_LENGTH][MAX_CHAR_LENGTH]; /*Bruger ingrediens structen til at lave en variable*/
    FILE *pshoppingList = fopen("shopping_list.txt", "w");
    char localName[15][MAX_CHAR_LENGTH];
    double localAmount[15];
    char localUnit[15][MAX_CHAR_LENGTH];
    char clear[] =  " ";
    int i = 0, k = 0, wipe;
    
    sscanf(database.ingredients[databaseIndex], "%s %lf %[^,],", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngriends[ingredientsIndex][i].name, localName[k]);
    newIngriends[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngriends[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*lf %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngriends[ingredientsIndex][i].name, localName[k]);
    newIngriends[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngriends[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*lf %*[^,], %*s %*lf %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngriends[ingredientsIndex][i].name, localName[k]);
    newIngriends[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngriends[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngriends[ingredientsIndex][i].name, localName[k]);
    newIngriends[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngriends[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngriends[ingredientsIndex][i].name, localName[k]);
    newIngriends[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngriends[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngriends[ingredientsIndex][i].name, localName[k]);
    newIngriends[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngriends[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %*s %*lf %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngriends[ingredientsIndex][i].name, localName[k]);
    newIngriends[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngriends[ingredientsIndex][i].unit, localUnit[k]);

    for (wipe = 0; wipe <= k; wipe++)
    {
        strcpy(localName[wipe], clear);
        localAmount[wipe] = 0;
        strcpy(localUnit[wipe], clear);
    }
    
    print_grocery_list(pshoppingList, newIngriends);
    
    fclose(pshoppingList);
}

/*Funktion til at lave en indkøbsliste*/
void print_grocery_list(FILE *shoppingList, ingredients ingredientsArray[MAX_ARRAY_LENGTH][MAX_CHAR_LENGTH]){
    int i = 0, j = 0;

    for (j = 0; j < 15; j++)
    {
        for (i = 0; i < 15; i++)
        {
            if (strcmp(ingredientsArray[j][i].name, ingredientsArray[j+1][i].name) == 0 && (ingredientsArray[j][i].amount != 0))
            {
                ingredientsArray[j+1][i].amount += ingredientsArray[j][i].amount;
                ingredientsArray[j][i].amount = 0;
            }
        }   
    }

    fprintf(shoppingList, "Usorteret array er: \n");
    for (j = 0; j < 15; j++)
    {
        for (i = 0; i < 15; i++)
        {
            if (ingredientsArray[j][i].amount != 0)
            {
                fprintf(shoppingList, "%s ", ingredientsArray[j][i].name);
                fprintf(shoppingList, "%.0lf ", ingredientsArray[j][i].amount);
                fprintf(shoppingList, "%s\n", ingredientsArray[j][i].unit);
            }   
        }   
    }

    qsort(ingredientsArray, MAX_ARRAY_LENGTH, (sizeof(char *)), myCompare);
    
    fprintf(shoppingList, "\n");
    fprintf(shoppingList, "Sorteret array er: \n");
    for (j = 0; j < 15; j++)
    {
        for (i = 0; i < 15; i++)
        {
            if (ingredientsArray[j][i].amount != 0)
            {
                fprintf(shoppingList, "%s ", ingredientsArray[j][i].name);
                fprintf(shoppingList, "%.0lf ", ingredientsArray[j][i].amount);
                fprintf(shoppingList, "%s\n", ingredientsArray[j][i].unit);
            }   
        }   
    }
}

/*Funktion til at lave madplan filen*/
void print_meal_plan(FILE *output, int weekdayIndex, int databaseIndex){
    char weekdays[7][10] = {"Mandag", "Tirsdag", "Onsdag", "Torsdag", "Fredag", "Lørdag", "Søndag"};

    /* Hvis weekdays[weekdayIndex] er Tirsdag eller Torsdag, så skal den printe et # mindre, */
    /* fordi disse dage er ét tegn længere end resten af ugens dage, så det ser pænt ud.     */
    if ((weekdays[weekdayIndex] == weekdays[1]) || (weekdays[weekdayIndex] == weekdays[3]))
    {
        fprintf(output, "###############################################################\n");
        fprintf(output, "########################### %s ###########################\n", weekdays[weekdayIndex]);
    } 
    else 
    {
        fprintf(output, "###############################################################\n");        
        fprintf(output, "########################### %s ############################\n", weekdays[weekdayIndex]);
    }

    fprintf(output,"%s\n", database.title[databaseIndex]);
    fprintf(output,"%s\n", database.description[databaseIndex]);
    fprintf(output,"%s\n", database.ingredients[databaseIndex]);
    
    if (database.vegetarian[databaseIndex] == FALSE)
    {
        fprintf(output,"Denne ret er ikke vegetarisk\n");
    }
    else
    {
        fprintf(output,"Denne ret er vegetarisk\n");
    }
    if (database.vegan[databaseIndex] == FALSE)
    {
        fprintf(output,"Denne ret er ikke vegansk\n");
    }
    else
    {
        fprintf(output,"Denne ret er vegansk\n");
    }
    fprintf(output,"Prisklasse: %d\n", database.price[databaseIndex]);
    fprintf(output,"Tid: %d minutter\n", database.time[databaseIndex]);
}


// Defining comparator function as per the requirement 
int myCompare(const void *ingredient_a, const void *ingredient_b) 
{   
    char** p1 = (char**) ingredient_a;
    char** p2 = (char**) ingredient_b;

    return strcmp(*p1, *p2);
}

/*
// Defining comparator function as per the requirement 
int myCompare(const void *ingredient_a, const void *ingredient_b) 
{   
    return strcmp(((ingredients *)ingredient_a)->name, ((ingredients *)ingredient_b)->name); 
}
 */