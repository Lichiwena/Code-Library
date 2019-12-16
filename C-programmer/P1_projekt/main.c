#include <stdlib.h> /* Standard library, brugt til random generator */
#include <stdio.h> /* Standard library, brugt til FILE */
#include <string.h> /* Standard library, brugt til string compare osv */
#include <time.h> /* Standard library, brugt til seed til random generator */
#include <conio.h> /* Standard library, brugt til system kommandoer*/
#include "main.h" /* Inkluderer main.h headerfilen */
#include "error.h" /*Inkluderer error.h headerfilen */

/*Foerste funktion der bliver kaldt*/
int main(void){
    FILE *pinputFile = fopen(INPUTFILE, "r");  /*Finder inputfilen*/
    FILE *p2inputFile = fopen(INPUTFILE, "r"); /*aabner input filen en anden gang til dynamisk lager allokering*/
    FILE *p3inputFile = fopen(INPUTFILE, "r"); /*Smart tekst*/
    FILE *psettingsFile = fopen(SETTINGSFILE, "r");
    int checkForEOF = getc(pinputFile); /*laeser foerste linje af inputfilen og saetter den checkForEOF til 1 hvis den kan laese en linje*/
    int databaseIndex = 0;
    int i = 0;
    int numberOfRecipes = count_index_numbers(p2inputFile);
    int **charsCounter = count_chars_title_description_ingridients(numberOfRecipes, p3inputFile);    
    srand(time(NULL));

    database.title = (char **)malloc(sizeof(char *) * numberOfRecipes);
    for(i = 0; i < numberOfRecipes; i++){
        database.title[i] = (char *)malloc(sizeof(char) * charsCounter[0][i]);
    }
    database.description = (char **)malloc(sizeof(char *) * numberOfRecipes);
    for(i = 0; i < numberOfRecipes; i++){
        database.description[i] = (char *)malloc(sizeof(char *) * charsCounter[1][i]);
    }
    database.ingredients = (char **)malloc(sizeof(char *) * numberOfRecipes);
    for(i = 0; i < numberOfRecipes; i++){
        database.ingredients[i] = (char *)malloc(sizeof(char *) * charsCounter[2][i]);
    }
    database.indexNumber = (int *)malloc(sizeof(int) * numberOfRecipes);
    database.vegetarian = (int *)malloc(sizeof(int) * numberOfRecipes);
    database.vegan = (int *)malloc(sizeof(int) * numberOfRecipes);
    database.price = (int *)malloc(sizeof(int) * numberOfRecipes);
    database.time = (int *)malloc(sizeof(int) * numberOfRecipes);

    if (pinputFile == NULL || p2inputFile == NULL || p3inputFile == NULL){
        error(4);
    }
    if (database.title == NULL || database.description == NULL || database.ingredients == NULL || database.indexNumber == NULL || database.vegetarian == NULL ||
             database.vegan == NULL || database.price == NULL || database.time == NULL){
        error(2);
    }
    
    if (psettingsFile == NULL){
        psettingsFile = fopen(SETTINGSFILE, "w");
        user_settings(psettingsFile, numberOfRecipes);
        fclose(psettingsFile);
        psettingsFile = fopen(SETTINGSFILE, "r");
        read_settings(psettingsFile);
    }
    else{
        read_settings(psettingsFile);
    }

    if (pinputFile == NULL){
        return(error(4));
    }
    else{
        while (checkForEOF != EOF){ /*Imens at den kan laese en linje koerer dette*/
            read_data(pinputFile, databaseIndex);
            databaseIndex++;
            checkForEOF = getc(pinputFile); /*Opdatere variablen*/
        }
    }

    menu(psettingsFile, numberOfRecipes);

    fclose(pinputFile);

    system("notepad.exe madplan.txt");

    return 0;
}

/*Taeller hvor mange retter der er i databasen*/
int count_index_numbers(FILE *input){
    int dishMax = 0;
    int checkForEOF = getc(input);
    
    while(checkForEOF != EOF){
        fscanf(input, "%*[^=]= %d %*[^\n] %*[^\n] %*[^\n] %*[^\n] %*[^\n] %*[^\n] %*[^\n]", &dishMax);
        checkForEOF = getc(input);
    }

    return dishMax + 1;
}

/*Taeller chars og returner et 2 dimensionelt int array*/
int** count_chars_title_description_ingridients(int numberOfRecipes, FILE *input){
    int **arr, j = 0, i = 0;
    int thingsToCount = 3;

    arr = (int **)malloc(sizeof(int *) * thingsToCount);
    for(i = 0; i < thingsToCount; i++){
        arr[i] = (int *)malloc(sizeof(int) * numberOfRecipes);
    }
    
    fscanf(input, "%*[^\n] ");

    while(j != numberOfRecipes){
        fscanf(input, "%*[^']'");
        arr[0][j]=0;
        while (getc(input) != '\''){
            arr[0][j]++;
        }

        fscanf(input, "%*[^']' ");

        arr[1][j] = 0;
        while (getc(input) != '\''){
            arr[1][j]++;
        }

        fscanf(input, "%*[^']' ");

        arr[2][j] = 0;
        while (getc(input) != '\''){
            arr[2][j]++;
        }

        j++;

        fscanf(input, "%*[^\n] %*[^\n] %*[^\n] %*[^\n] %*[^\n] ");
    }

    return arr;
}

/*Stiller brugeren spoergsmaal og gemmer data'en*/
void user_settings(FILE *usersettings, int numberOfRecipes){
    int vegan, vegetarian, pricerange_max, answer3 = 0;
    char answer1 = 'a', answer2 = 'b';
    while (answer1 != 'J' && answer1 != 'j' && answer1 != 'N' && answer1 != 'n'){
        printf("Er du veganer? J/N ");
        scanf(" %c", &answer1);
        if (answer1 == 'J' || answer1 == 'j'){
            vegan = 1;
        }
        else if (answer1 == 'N' || answer1 == 'n'){
            vegan = 0;
        }
        else{
            error(1);
        }
        
        fflush(stdin);
    }
    if (vegan == 0){
        while (answer2 != 'J' && answer2 != 'j' && answer2 != 'N' && answer2 != 'n'){
            printf("Er du vegetar? J/N ");
            scanf("%c", &answer2);
            if (answer2 == 'J' || answer2 == 'j'){
                vegetarian = 1;
            }
            else if (answer2 == 'N' || answer2 == 'n'){
                vegetarian = 0;
            }
            else{
                error(1);
            }
            
            fflush(stdin);
        }
    }
    else if (vegan == 1){
        vegetarian = 1;
    }
    while (answer3 != 1 && answer3 != 2 && answer3 != 3 && answer3 != 4 && answer3 != 5){
        printf("Hvilken prisklasse vil du max have? 1-5 ");
        scanf("%d", &answer3);
        printf("\n");
        if (answer3 == 1){
            pricerange_max = 1;
        }
        else if (answer3 == 2){
            pricerange_max = 2;
        }
        else if (answer3 == 3){
            pricerange_max = 3;
        }
        else if (answer3 == 4){
            pricerange_max = 4;
        }
        else if (answer3 == 5){
            pricerange_max = 5;
        }
        else{
            error(1);
        }

        fflush(stdin);
    }
    fprintf(usersettings, "Vegan %d\n", vegan);
    fprintf(usersettings, "Vegetarian %d\n", vegetarian);
    fprintf(usersettings, "Price %d\n", pricerange_max);
    fclose(usersettings);
    menu(usersettings, numberOfRecipes);
}

/*Laeser brugerens data'en*/
void read_settings(FILE *psettingsFile){
    fscanf(psettingsFile, "%*s %d %*s %d %*s %d", &settings.vegan, &settings.vegetarian, &settings.price);
    if (psettingsFile == NULL){
        error(3);
    }
}

/*Funktion til at laese databasen og gemme det forskellige ting i variabler*/
void read_data(FILE *input, int databaseIndex){
    /*"%" med "*" betyder at den skal laese det men ikke gemme det*/
    fscanf(input, "%*[^=]= %d %*[^']' %[^']' %*[^']' %[^']' %*[^']' %[^']'  %*[^=]= %d %*[^=]= %d %*[^=]= %d %*[^=]= %d", &database.indexNumber[databaseIndex], database.title[databaseIndex], 
    database.description[databaseIndex], database.ingredients[databaseIndex], &database.vegetarian[databaseIndex], &database.vegan[databaseIndex], &database.price[databaseIndex], &database.time[databaseIndex]);
}

/*Menu til brugeren kan vaelge funktioner*/
void menu(FILE *psettingsFile, int numberOfRecipes){
    FILE *poutFile = fopen(OUTPUTFILE, "w"); /*Laver inputfilen*/
    int checkValue = 0, randomValue[7], tempValue[7], weekdayIndex = 0, ingredientsIndex = 0;
    int userInput = 0;
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
        psettingsFile = fopen(SETTINGSFILE, "w");
        user_settings(psettingsFile, numberOfRecipes);
        fclose(psettingsFile);
        fopen(SETTINGSFILE, "r");
    }
    else if (userInput == 3){
        clear_screen();
        EXIT_SUCCESS;
    }
    else{
        error(1);
        fflush(stdin);
        menu(psettingsFile, numberOfRecipes);
    }
}

/*Funktion til at "lave" ingridenser*/
void make_ingredients(int databaseIndex, int ingredientsIndex){
    ingredients newIngredients[MAX_ARRAY_LENGTH][MAX_CHAR_LENGTH]; /*Bruger ingrediens structen til at lave en variable*/
    FILE *pshoppingList = fopen(SHOPPINGLIST, "w");
    char localName[MAX_AMOUNT_OF_INGREDIENTS][MAX_CHAR_LENGTH];
    double localAmount[MAX_AMOUNT_OF_INGREDIENTS];
    char localUnit[MAX_AMOUNT_OF_INGREDIENTS][MAX_CHAR_LENGTH];
    char clear[] =  " ";
    int i = 0, k = 0, wipe;
    
    sscanf(database.ingredients[databaseIndex], "%s %lf %[^,],", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngredients[ingredientsIndex][i].name, localName[k]);
    newIngredients[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngredients[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*d %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngredients[ingredientsIndex][i].name, localName[k]);
    newIngredients[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngredients[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*d %*[^,], %*s %*d %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngredients[ingredientsIndex][i].name, localName[k]);
    newIngredients[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngredients[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngredients[ingredientsIndex][i].name, localName[k]);
    newIngredients[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngredients[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngredients[ingredientsIndex][i].name, localName[k]);
    newIngredients[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngredients[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngredients[ingredientsIndex][i].name, localName[k]);
    newIngredients[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngredients[ingredientsIndex][i].unit, localUnit[k]);
    k++;
    i++;
    sscanf(database.ingredients[databaseIndex], "%*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %*s %*d %*[^,], %s %lf %s", localName[k], &localAmount[k], localUnit[k]);
    strcpy(newIngredients[ingredientsIndex][i].name, localName[k]);
    newIngredients[ingredientsIndex][i].amount = localAmount[k];
    strcpy(newIngredients[ingredientsIndex][i].unit, localUnit[k]);

    for (wipe = 0; wipe <= k; wipe++){
        strcpy(localName[wipe], clear);
        localAmount[wipe] = 0;
        strcpy(localUnit[wipe], clear);
    }
    
    print_grocery_list(pshoppingList, newIngredients);
    
    fclose(pshoppingList);
}

/*Funktion til at lave en indkoebsliste*/
void print_grocery_list(FILE *shoppingList, ingredients ingredientsArray[MAX_ARRAY_LENGTH][MAX_CHAR_LENGTH]){
    int i = 0, j = 0;
    fprintf(shoppingList, "Denne uges indkoebsliste\n");
    /*for (j = 0; j < 8; j++){
        for (i = 0; i < 8; i++){
            if (strcmp(ingredientsArray[j][i].name, ingredientsArray[j+1][i].name) == 0 && (ingredientsArray[j][i].amount != 0)){
                ingredientsArray[j+1][i].amount += ingredientsArray[j][i].amount;
                ingredientsArray[j][i].amount = 0;
            }
        }   
    }*/
    for (j = 0; j < 8; j++){
        for (i = 0; i < 8; i++){
            if (ingredientsArray[j][i].amount != 0){
                fprintf(shoppingList, " - %s ", ingredientsArray[j][i].name);
                fprintf(shoppingList, "%.0lf ", ingredientsArray[j][i].amount);
                fprintf(shoppingList, "%s\n", ingredientsArray[j][i].unit);
            }   
        }   
    }
}

/*Funktion til at udvaelge hvilken madplan der skal printes*/
void print_meal_plan(FILE *output, int weekdayIndex, int databaseIndex, int numberOfRecipes){
    if (settings.vegan == FALSE && (settings.vegetarian == TRUE)){
        print_vegetarian_meal_plan(output, weekdayIndex, databaseIndex, numberOfRecipes);
    }
    else if (settings.vegan == TRUE){
        print_vegan_meal_plan(output, weekdayIndex, databaseIndex, numberOfRecipes);
    }
    else{
        print_standard_meal_plan(output, weekdayIndex, databaseIndex);
    }
}

/*Printer en vegantarisk madplan*/
void print_vegetarian_meal_plan(FILE *output, int weekdayIndex, int databaseIndex, int numberOfRecipes){
    char weekdays[7][10] = {"Mandag", "Tirsdag", "Onsdag", "Torsdag", "Fredag", "Loerdag", "Soendag"};
    int i = 0;
    int *vegeetarian_array = malloc(sizeof(int) * numberOfRecipes);

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
    
    if (database.vegetarian[databaseIndex] == TRUE){
        vegeetarian_array[i] = database.indexNumber[databaseIndex];
    }
    else
    {
        while (database.vegetarian[databaseIndex] != TRUE)
        {
            databaseIndex++;
        }
        vegeetarian_array[i] = database.indexNumber[databaseIndex];
    }

    printf("%s\n", database.title[vegeetarian_array[i]]);
    fprintf(output, "%s\n", database.title[vegeetarian_array[i]]);
    fprintf(output, "%s\n", database.description[vegeetarian_array[i]]);
    fprintf(output, "%s\n", database.ingredients[vegeetarian_array[i]]);
    fprintf(output, "Denne ret er vegetarisk\n");
    fprintf(output, "Denne ret er vegansk\n");
    printf("Prisklasse: %d\n", database.price[vegeetarian_array[i]]);
    fprintf(output, "Prisklasse: %d\n", database.price[vegeetarian_array[i]]);
    printf("Tid: %d minutter\n", database.time[vegeetarian_array[i]]);
    fprintf(output, "Tid: %d minutter\n", database.time[vegeetarian_array[i]]);

    free(vegeetarian_array);
}

/*Printer en vegansk madplan*/
void print_vegan_meal_plan(FILE *output, int weekdayIndex, int databaseIndex, int numberOfRecipes){
    char weekdays[7][10] = {"Mandag", "Tirsdag", "Onsdag", "Torsdag", "Fredag", "Loerdag", "Soendag"};
    int i = 0;
    int *vegan_array = malloc(sizeof(int) * numberOfRecipes);

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
    
    if (database.vegan[databaseIndex] == TRUE){
        vegan_array[i] = database.indexNumber[databaseIndex];
    }
    else
    {
        while (database.vegan[databaseIndex] != TRUE)
        {
            databaseIndex++;
        }
        vegan_array[i] = database.indexNumber[databaseIndex];
    }

    printf("%s\n", database.title[vegan_array[i]]);
    fprintf(output, "%s\n", database.title[vegan_array[i]]);
    fprintf(output, "%s\n", database.description[vegan_array[i]]);
    fprintf(output, "%s\n", database.ingredients[vegan_array[i]]);
    fprintf(output, "Denne ret er vegetarisk\n");
    fprintf(output, "Denne ret er vegansk\n");
    printf("Prisklasse: %d\n", database.price[vegan_array[i]]);
    fprintf(output, "Prisklasse: %d\n", database.price[vegan_array[i]]);
    printf("Tid: %d minutter\n", database.time[vegan_array[i]]);
    fprintf(output, "Tid: %d minutter\n", database.time[vegan_array[i]]);

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
    int newRandomIndex = -1;
    int weekday = 0;
    srand(time(NULL));

    printf("\nFlere informationer om madplanen findes i madplan.txt-filen, blandt andet opskrifter.\n");
    printf("Er du tilfreds med din madplan? J/N \n");
    scanf(" %c", &satisfied);

    if (satisfied == 'N' || satisfied == 'n'){
        printf("\nDu har valgt, at du ikke er tilfreds. \nHvilken dag er du ikke tilfreds med? (Indtast nummer paa dagen)\n");
        scanf("%d", &weekday);
        while(weekday > 7 || weekday < 1){
            error(1);
            fflush(stdin);
            scanf("%d", &weekday);
        }

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
    else if (satisfied != 'N' && satisfied != 'n' && satisfied != 'J' && satisfied != 'j'){
        error(1);
        satisfied_with_mealplan(output, numberOfRecipes);
    }
    
    return 0;
}

/*Hvis brugeren er utilfreds spoerger og aendre denne funktion*/
int find_new_dish(char krit1[], char krit2[], int numberOfRecipes){
    int i = 0;
    int tempIndex[MAX_ARRAY_LENGTH];
    int tempRandom = -1;

    for (i = 0; i < numberOfRecipes; i++){
        if (strstr(database.ingredients[i], krit1) || strstr(database.ingredients[i], krit2)){
            tempIndex[i] = database.indexNumber[i];
        }
        else{
            tempIndex[i] = -1;
        }
    }

    for (i = 0; i < numberOfRecipes; ++i){
        if (tempIndex[i] != -1){
            while (tempRandom == -1){
                tempRandom = tempIndex[rand() % numberOfRecipes];
            }
            i = numberOfRecipes;
        }
    }
    return tempRandom;
}

void clear_screen(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}