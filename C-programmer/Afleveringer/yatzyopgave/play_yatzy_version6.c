/* Navn: Sarah Mølleskov Frandsen   *
 * Email: sfrand19@student.aau.dk   *
 * Gruppe: DAT A311                 *
 * Studieretning: Datalogi          */

/* Jeg har anvendt Kurts element compare funktion, som vi fik vist til den forelæsning,   *
 * hvor vi arbejde med sorteringsalgoritmer. Derudover har jeg også anvendt qsort som min * 
 * foretrukne sorteringsalgoritme i denne aflevering.                                     */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIE_MAX_EYES 6
#define BONUS 50

void Roll_Multiple_Dice(int n, int dice_rolls[]);
void Print_Dice_Rolls_Array(int n, int dice_rolls[]);
void Print_New_Line_in_Table(void);
void Sum_of_Scoreboard(int round_number, int score, int score_board[]);
void Print_Sum_of_Scoreboard(int score_board[]);
void Check_for_Bonus(int score_board[]);
void Play_Yatzy(int n, int dice_rolls[], int score_board[]);
void Find_Numbers_One_to_Six(int n, int dice_rolls[], int round_number, int score_board[]);
void Find_One_Pair(int n, int dice_rolls[], int round_number, int score_board[]);
void Find_Two_Pairs(int n, int dice_rolls[], int round_number, int score_board[]);
void Find_Three_of_a_Kind(int n, int dice_rolls[], int round_number, int score_board[]);
void Find_Four_of_a_Kind(int n, int dice_rolls[], int round_number, int score_board[]);
void Check_for_Small_Straight(int n, int dice_rolls[], int round_number, int score_board[]);
void Check_for_Big_Straight(int n, int dice_rolls[], int round_number, int score_board[]);
void Check_for_Full_House(int n, int dice_rolls[], int round_number, int score_board[]);
void Find_Chance(int n, int dice_rolls[], int round_number, int score_board[]);
void Check_for_Yatzy(int n, int dice_rolls[], int round_number, int score_board[]);
int element_compare(const void *ip1, const void *ip2);

int main(void)
{
    int n = 0;
    int *dice_rolls = 0;
    int *score_board = 0;
    char play_again = 'a';

    srand(time(NULL));

    do {
        printf("Please enter the number of dice you would like to play with:\n");
        scanf(" %d", &n);
            while (n < 5)
            {
                printf("Please enter a number eqaul to or greater than 5.\n");
                scanf(" %d", &n);
            }

            dice_rolls = calloc(n, sizeof(int));
            score_board = calloc(16, sizeof(int));

            Print_New_Line_in_Table();
            Play_Yatzy(n, dice_rolls, score_board);
            Print_New_Line_in_Table();
            Print_Sum_of_Scoreboard(score_board);
            Print_New_Line_in_Table();

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

/* Denne funktion printer mit terningekast for den pågældende runde. */
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

/* Denne funktion printer en ny linje i tabellen. */
void Print_New_Line_in_Table(void)
{
    printf("_________________________________________________________________________\n");
}

/* Denne funktion finder scoren for den pågældende runder og lægger derefter værdien     *
 * over i variablen score. Summen af alle runderne får således index 0 i mit score_board *
 * array, og derfor vil scoren for alle runderne 1, 2, 3... passe med deres indextal.    */
void Sum_of_Scoreboard(int round_number, int score, int score_board[])
{
    score_board[round_number] = score;
    score_board[0] = (score_board[0] + score);
}

/* Denne funktion printer den totale sum af scoreboardet. */
void Print_Sum_of_Scoreboard(int score_board[])
{
    printf("Your total score is: %d \n", score_board[0]);
}

/* Denne funktion tjekker, om der er bonus efter de første seks runder af spillet. */
void Check_for_Bonus(int score_board[])
{
    if (score_board[0] >= 63)
    {
        printf("You earned %d points in the first six rounds, resulting in 50 bonus points!\n", score_board[0]);
        score_board[0] = score_board[0] + BONUS;
    } else {
        printf("You earned %d points which does not earn you a bonus this time around \n", score_board[0]);
    }
}

/* Denne funktion indkapsler mit Yatzy spil. Dette gøres vha. en switch, som switcher på *
 * den pågældende rundes nummer og kalder dertilhørende funktion.                        */
void Play_Yatzy(int n, int dice_rolls[], int score_board[])
{
    int round_number = 1;

    enum Yatzy_Rounds {Ones = 1, Twos, Threes, Fours, Fives, Sixes, One_Pair, Two_Pairs,
                       Three_of_a_Kind, Four_of_a_Kind, Small_Straight, Big_Straight,
                       Full_House, Chance, Yatzy};

    for (round_number = 1; round_number <= 15; ++round_number)
    {
        switch (round_number)
        {
            case Ones: case Twos: case Threes: case Fours: case Fives: case Sixes:
                printf("|| Round number %4d ", round_number);
                Find_Numbers_One_to_Six(n, dice_rolls, round_number, score_board);
                break;
            case One_Pair:
                Print_New_Line_in_Table();
                Check_for_Bonus(score_board);
                Print_New_Line_in_Table();
                printf("|| Round number %4d ", round_number);
                Find_One_Pair(n, dice_rolls, round_number, score_board);
                break;
            case Two_Pairs:
                printf("|| Round number %4d ", round_number);
                Find_Two_Pairs(n, dice_rolls, round_number, score_board);
                break;
            case Three_of_a_Kind:
                printf("|| Round number %4d ", round_number);
                Find_Three_of_a_Kind(n, dice_rolls, round_number, score_board);
                break;
            case Four_of_a_Kind:
                printf("|| Round number %4d ", round_number);
                Find_Four_of_a_Kind(n, dice_rolls, round_number, score_board);
                break;
            case Small_Straight:
                printf("|| Round number %4d ", round_number);
                Check_for_Small_Straight(n, dice_rolls, round_number, score_board);
                break;
            case Big_Straight:
                printf("|| Round number %4d ", round_number);
                Check_for_Big_Straight(n, dice_rolls, round_number, score_board);
                break;
            case Full_House:
                printf("|| Round number %4d ", round_number);
                Check_for_Full_House(n, dice_rolls, round_number, score_board);
                break;
            case Chance:
                printf("|| Round number %4d ", round_number);
                Find_Chance(n, dice_rolls, round_number, score_board);
                break;
            case Yatzy:
                printf("|| Round number %4d ", round_number);
                Check_for_Yatzy(n, dice_rolls, round_number, score_board);
                break;
        }
    }
}

/* Denne funktion kører de første seks runder af spillet. */
void Find_Numbers_One_to_Six(int n, int dice_rolls[], int round_number, int score_board[])
{
    int i = 0, 
        score = 0,
        selected_amount_of_dice = 0;

    Roll_Multiple_Dice(n, dice_rolls);   

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == round_number)
        {
            score = score + round_number;
            selected_amount_of_dice = selected_amount_of_dice + 1;
            if (selected_amount_of_dice == 5)
            {
                i = n;
            }
        }
    }  

    printf("|| "); 
    
    for (i = 0; i < n; ++i)
        {
            printf("%d ", dice_rolls[i]);
        }
    printf("|| Points this round: %4d ||\n", score);

    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion finder et par.*/
void Find_One_Pair(int n, int dice_rolls[], int round_number, int score_board[])
{
    int i = 0,
        score = 0,
        pair = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    for (i = (n - 1); i > 0; --i)
        {
            if(dice_rolls[i] == dice_rolls[i - 1])
            {
                score = (dice_rolls[i] * 2);
                printf(" Points this round: %4d ||\n", score);
                pair = 1;
                i = 0;
            }
        }
    if (pair != 1)
    {
        printf(" Points this round: %4d ||\n", score);
    }
    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion finder to par, som ikke må være ens (da dette ville svare til 4 ens).*/
void Find_Two_Pairs(int n, int dice_rolls[], int round_number, int score_board[])
{
    int i = 0,
        pairs = 0,
        block_same_pair = 0,
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

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
                printf(" Points this round: %4d ||\n", score);
                i = 0;
            }
        }
    if (pairs != 2)
    {
        score = 0;
        printf(" Points this round: %4d ||\n", score);
    }
    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion finder tre ens. */
void Find_Three_of_a_Kind(int n, int dice_rolls[], int round_number, int score_board[])
{
    int i = 0,
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    for (i = (n - 1); i >= 2; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 2])
        {
            score = (dice_rolls[i] * 3);
            i = 0;
        }
    } 
    printf(" Points this round: %4d ||\n", score);

    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion finder fire ens. */
void Find_Four_of_a_Kind(int n, int dice_rolls[], int round_number, int score_board[])
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
    printf(" Points this round: %4d ||\n", score);

    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion tjekker, om tallene fra 1-5 er slået. Hvis alle tallene er slået, * 
 * gives der point for lille straight.                                              */
void Check_for_Small_Straight(int n, int dice_rolls[], int round_number, int score_board[])
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
    printf(" Points this round: %4d ||\n", score);

    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion gør det samme som Check_for_Small_Straight, men med tallene 2-6 i stedet. */
void Check_for_Big_Straight(int n, int dice_rolls[], int round_number, int score_board[])
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
    printf(" Points this round: %4d ||\n", score);

    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion tjekker for fuldt hus ved først at tjekke for tre ens, dernæst tjekke for * 
 * et par, og til sidst tjekke, om der både er fundet tre ens og et par.                    */
void Check_for_Full_House(int n, int dice_rolls[], int round_number, int score_board[])
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
        if (dice_rolls[i] == dice_rolls[i - 2])
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
        printf(" Points this round: %4d ||\n", score);
    } else {
        score = 0;
        printf(" Points this round: %4d ||\n", score);
    }
    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion finder chancen ved at sortere tallene og kun vælge de fem højeste tal ud. */
void Find_Chance(int n, int dice_rolls[], int round_number, int score_board[])
{
    int i = 0,
        score = 0;

    Roll_Multiple_Dice(n, dice_rolls);

    qsort(dice_rolls, n, sizeof(int), element_compare);

    Print_Dice_Rolls_Array(n, dice_rolls);

    for (i = (n - 1); i > (n - 6); --i)
    {
        score = score + dice_rolls[i]; 
    }
    printf(" Points this round: %4d ||\n", score);

    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Denne funktion finder ud af, om der er 5 ens (yatzy). */
void Check_for_Yatzy(int n, int dice_rolls[], int round_number, int score_board[])
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
            score = (dice_rolls[i] * 5) + BONUS;
            i = 0;
        }
    } 
    printf(" Points this round: %4d ||\n", score);

    Sum_of_Scoreboard(round_number, score, score_board);
}

/* Kurts element compare funktion. */
int element_compare(const void *ip1, const void *ip2)
{
    int result;
    int *ipi1 = (int *)ip1,
        *ipi2 = (int *)ip2;

    if (*ipi1 < *ipi2)
        result = -1;
    else if (*ipi1 > *ipi2)
        result = 1;
    else
        result = 0;

    return result;
}