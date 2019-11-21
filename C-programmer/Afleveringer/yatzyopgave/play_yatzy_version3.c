/* Min aflevering, som kan alt bortset fra at printe score og bonus.
   Aflevering uden switch. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIE_MAX_EYES 6

void Roll_Multiple_Dice(int n, int dice_rolls[]);
void Print_Dice_Rolls_Array(int n, int dice_rolls[]);
void Print_New_Line_in_Table(void);
void Find_Numbers_One_to_Six(int n, int dice_rolls[], int number_I_want_to_find);
void Find_One_Pair(int n, int dice_rolls[]);
void Find_Two_Pairs(int n, int dice_rolls[]);
void Find_Three_of_a_Kind(int n, int dice_rolls[]);
void Find_Four_of_a_Kind(int n, int dice_rolls[]);
void Check_for_Small_Straight(int n, int dice_rolls[]);
void Check_for_Big_Straight(int n, int dice_rolls[]);
void Check_for_Full_House(int n, int dice_rolls[]);
void Find_Chance(int n, int dice_rolls[]);
void Check_for_Yatzy(int n, int dice_rolls[]);
int element_compare(const void *ip1, const void *ip2);

int main(void)
{
    int n = 0,
        score = 0,
        number_I_want_to_find = 0;
    int *dice_rolls = 0;
    char play_again = 'a';

    srand(time(NULL));

    /* Min do-while løkke kører mindst én gang, og så længe play_again == y, så kører løkken.*/
    do {
        printf("Please enter the number of dice you would like to play with:\n");
        scanf(" %d", &n);
            while (n < 5)
            {
                printf("Please enter a number eqaul to or greater than 5.\n");
                scanf(" %d", &n);
            }

            /* Her allokeres space til mit array via calloc og pladsen assignes til arrayet dice_rolls. */
            dice_rolls = calloc(n, sizeof(int));

            Print_New_Line_in_Table();

            for (number_I_want_to_find = 1; number_I_want_to_find <= 6; ++number_I_want_to_find)
            {
                Find_Numbers_One_to_Six(n, dice_rolls, number_I_want_to_find);
            }

            Print_New_Line_in_Table();

            Find_One_Pair(n, dice_rolls);
            Find_Two_Pairs(n, dice_rolls);
            Find_Three_of_a_Kind(n, dice_rolls);
            Find_Four_of_a_Kind(n, dice_rolls);
            Check_for_Small_Straight(n, dice_rolls);
            Check_for_Big_Straight(n, dice_rolls);
            Check_for_Full_House(n, dice_rolls);
            Find_Chance(n, dice_rolls);
            Check_for_Yatzy(n, dice_rolls);

        printf("\nWould you like to play again? Press 'y' for yes and 'n' for no.\n");
        scanf(" %c", &play_again);

    } while (play_again == 'y');

    printf("Thank you for playing yatzy!\n");

    free(dice_rolls);

return(0);
}

/* Denne funktion kaster n terninger. */
void Roll_Multiple_Dice(int n, int dice_rolls[])
{
    int i = 0;

    for (i = 0; i < n; ++i)
    {
        dice_rolls[i] = rand() % DIE_MAX_EYES + 1;
    }  
}

/* Denne funktion printer mit dice roll for den pågældende runde. */
void Print_Dice_Rolls_Array(int n, int dice_rolls[])
{
    int i = 0; 

    printf("||");
    for (i = 0; i < n; ++i)
        {
            printf(" %d", dice_rolls[i]);
        }
    printf(" ||");
}

void Print_New_Line_in_Table(void)
{
    printf("-------------------------------------------------------\n");
}

/* Denne funktion kører de første 6 runder af spillet. */
void Find_Numbers_One_to_Six(int n, int dice_rolls[], int number_I_want_to_find)
{
    int i = 0, 
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);   

    /* Kører i op fra 0 til én mindre end 5.
    Hvis tallet i mit array (starter med tallet med index 0) er det tal,
    jeg gerne vil finde (1 for første gennemgang), så tælles score op med
    det tal jeg gerne vil finde (altså 1 ved første gennemgang). Ellers
    gemmes tallet ikke. */
    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == number_I_want_to_find)
        {
            score = score + number_I_want_to_find;
        }
    }  

    printf("|| "); 
    
    /* Her printes værdierne i arrayet ud vha. en forløkke. */
    for (i = 0; i < n; ++i)
        {
            printf("%d ", dice_rolls[i]);
        }
    printf("|| Points this round: %d ||\n", score);
}

/* Denne funktion finder et par. Først bruges qsort til at sortere 
   elementerne fra mindste element til største element, dernæst
   sammenlignes de to største elementer. Hvis disse er lig hinanden,
   er der et par. Hvis ikke, kører man ned gennem rækken, til der 
   findes det største par i rækken. */
void Find_One_Pair(int n, int dice_rolls[])
{
    int i = 0,
        pair = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    /* Yoinket fra stackoverflow, men reversed */
    /* Hvis de sidste to elementer i mit array er ens, så printes det
    højeste par ud. Hvis ikke, så tælles i ned med 1, så men tjekker
    næste to elementer i rækken. Hvis de to elementer er ens,
    sættes i til 0, og forløkken stopper, så den ikke skal finde
    flere par (da vi kun vil finde det højeste par).*/
    for (i = (n - 1); i > 0; --i)
        {
            if(dice_rolls[i] == dice_rolls[i - 1])
            {
                printf(" Points this round: %d ||\n", (dice_rolls[i] * 2));
                pair = 1;
                i = 0;
            }
        }
    if (pair != 1)
    {
        printf(" Points this round: 0 ||\n");
    }
}

void Find_Two_Pairs(int n, int dice_rolls[])
{
    int i = 0,
        pairs = 0,
        block_same_pair = 0,
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    /* Scoren tælles op hver gang, der findes et par, med øjnene på
    terningen (f.eks. 6) ganget med to (da det er et par). Til sidst
    printes scoren, når der er fundet to par. */
    for (i = (n - 1); i > 0; --i)
        {
            if(dice_rolls[i] == dice_rolls[i - 1] && (pairs < 2) && (dice_rolls[i] != block_same_pair))
                {
                block_same_pair = dice_rolls[i];
                score = score + (dice_rolls[i] * 2);
                ++pairs;              
            }
            
            if (pairs == 2)
            {
                printf(" Points this round: %d ||\n", score);
                i = 0;
            }
        }
    if (pairs != 2)
    {
        printf(" Points this round: 0 ||\n");
    }
}

void Find_Three_of_a_Kind(int n, int dice_rolls[])
{
    int i = 0,
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    /* i >= 2 - Men HVORFOR 2? Fordi, hvis den er nået til elementet på
    index 2, så sammenligner den med index 0, som er det sidste element
    tilbage i array'et. Den kan ikke blive lavere end 2, fordi så 
    sammenlignes der med et element, som ikke findes i array'et. */
    for (i = (n - 1); i >= 2; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 2]) /* Hvis index n-1 er lig med den, der er to pladser længere til venstre, så TRUE. */
        {
            score = (dice_rolls[i] * 3);
            i = 0;
        }
    } 
    printf(" Points this round: %d ||\n", score);
}

void Find_Four_of_a_Kind(int n, int dice_rolls[])
{
    int i = 0,
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    for (i = (n - 1); i >= 3; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 3]) 
        {
            score = (dice_rolls[i] * 4);
            i = 0;
        }
    } 
    printf(" Points this round: %d ||\n", score);
}

void Check_for_Small_Straight(int n, int dice_rolls[])
{
    int i = 0,
        score = 0,
        found_one = 0,
        found_two = 0,
        found_three = 0,
        found_four = 0,
        found_five = 0,
        found_small_straight = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    Print_Dice_Rolls_Array(n, dice_rolls);

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == 1)
        {
            found_one = 1;
        }
        if (dice_rolls[i] == 2)
        {
            found_two = 2;
        }
        if (dice_rolls[i] == 3)
        {
            found_three = 3;
        }
        if (dice_rolls[i] == 4)
        {
            found_four = 4;
        }
        if (dice_rolls[i] == 5)
        {
            found_five = 5;
        }
        if (found_one == 1 && found_two == 2 && found_three == 3 && found_four == 4 && found_five == 5)
        {
            found_small_straight = (found_one + found_two + found_three + found_four + found_five);
            score = found_small_straight;
            i = n;
        }
    }
    printf(" Points this round: %d ||\n", score);
}

void Check_for_Big_Straight(int n, int dice_rolls[])
{
    int i = 0,
        score = 0,
        found_two = 0,
        found_three = 0,
        found_four = 0,
        found_five = 0,
        found_six = 0,
        found_big_straight = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    Print_Dice_Rolls_Array(n, dice_rolls);

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == 2)
        {
            found_two = 2;
        }
        if (dice_rolls[i] == 3)
        {
            found_three = 3;
        }
        if (dice_rolls[i] == 4)
        {
            found_four = 4;
        }
        if (dice_rolls[i] == 5)
        {
            found_five = 5;
        }
        if (dice_rolls[i] == 6)
        {
            found_six = 6;
        }
        if (found_two == 2 && found_three == 3 && found_four == 4 && found_five == 5 && found_six == 6)
        {
            found_big_straight = (found_two + found_three + found_four + found_five + found_six);
            score = found_big_straight;
            i = n;
        }
    }
    printf(" Points this round: %d ||\n", score);
}

void Check_for_Full_House(int n, int dice_rolls[])
{
    int i = 0,
        score = 0,
        three_of_a_kind_number = 0,
        found_a_pair = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);
    
    for (i = (n - 1); i >= 2; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 2]) /* Hvis index n-1 er lig med den, der er to pladser længere til venstre, så TRUE. */
        {
            three_of_a_kind_number = dice_rolls[i];
            score = score + (dice_rolls[i] * 3);
            i = 0;
        }
    } 

    if (score != 0)
    {
        for (i = (n - 1); i > 0; --i)
        {
            if((dice_rolls[i] == dice_rolls[i - 1]) && (dice_rolls[i] != three_of_a_kind_number))
            {
                score = score + (dice_rolls[i] * 2);
                found_a_pair = 1;
                i = 0;
            }
        }   
    }
    
    if ((three_of_a_kind_number != 0) && (found_a_pair == 1))
    {
        printf(" Points this round: %d ||\n", score);
    } else {
        score = 0;
        printf(" Points this round: %d ||\n", score);
    }
}

void Find_Chance(int n, int dice_rolls[])
{
    int i = 0,
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    /* i skal være (n - 1), da det er det tal med højest index, altså
    det første i rækken fra højre. For-løkken skal køre for i > (n - 6),
    da dette er det 5. tal fra højre, som jo er de tal, vi skal bruge.
    Derfor køres for-løkken 5 gange. */
    for (i = (n - 1); i > (n - 6); --i)
    {
        /* Scoren tælles op med det pågældende antal 
        øjne på terningen, for hver gang, for-loopet kører. */
        score = score + dice_rolls[i]; 
    }
    printf(" Points this round: %d ||\n", score);
}

/* Denne funktion finder ud af, om der er 5 ens vha. qsort. */
void Check_for_Yatzy(int n, int dice_rolls[])
{
    int i = 0,
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    for (i = (n - 1); i > 4; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 4]) 
        {
            score = 50 + (dice_rolls[i] * 5);
            i = 0;
        }
    } 
    printf(" Points this round: %d ||\n", score);
}

/* Kurts element compare funktion. */
int element_compare(const void *ip1, const void *ip2)
{
    int result;
    int *ipi1 = (int *)ip1,         /* Cast parameters to pointers to int */
        *ipi2 = (int *)ip2;

    if (*ipi1 < *ipi2)
        result = -1;
    else if (*ipi1 > *ipi2)
        result = 1;
    else
        result = 0;

    return result;
}