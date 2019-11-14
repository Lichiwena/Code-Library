#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIE_MAX_EYES 6

void roll_multiple_dies(int n, int dice_rolls[]);
void Number_of_Ones(int n, int dice_rolls[]);
void Number_of_Twos(int n, int dice_rolls[]);
void Number_of_Threes(int n, int dice_rolls[]);
void Number_of_Fours(int n, int dice_rolls[]);
void Number_of_Fives(int n, int dice_rolls[]);
void Number_of_Sixes(int n, int dice_rolls[]);

int main(void)
{
    int n = 0,
        i = 0,
        score = 0;
    int *dice_rolls = 0;
    char play_again = 'a';

    srand(time(NULL));

    /* Min do-while løkke kører mindst én gang, og så længe play_again == y, så kører løkken.*/
    do {
        printf("Please enter the number of dies you would like to play with:\n");
        scanf(" %d", &n);
        printf("n is: %d.\n", n); /* Tjekker */
            while (n < 5)
            {
                printf("Please enter a number eqaul to or greater than 5.\n");
                scanf(" %d", &n);
            }

            /* Her allokeres space til mit array via calloc og pladsen assignes til arrayet dice_rolls. */
            dice_rolls = calloc(n, sizeof(int));

            printf("n is again: %d.\n", n); /* Tjekker */

            Number_of_Ones(n, dice_rolls);
            printf(" You rolled:");
            for (i = 0; i < n; ++i)
            {
                printf(" %d ", dice_rolls[i]);
            }
            Number_of_Twos(n, dice_rolls);
            printf(" You rolled:");
            for (i = 0; i < n; ++i)
            {
                printf(" %d ", dice_rolls[i]);
            }
            Number_of_Threes(n, dice_rolls);
            printf(" You rolled:");
            for (i = 0; i < n; ++i)
            {
                printf(" %d ", dice_rolls[i]);
            }
            Number_of_Fours(n, dice_rolls);
            printf(" You rolled:");
            for (i = 0; i < n; ++i)
            {
                printf(" %d ", dice_rolls[i]);
            }
            Number_of_Fives(n, dice_rolls);
            printf(" You rolled:");
            for (i = 0; i < n; ++i)
            {
                printf(" %d ", dice_rolls[i]);
            }
            Number_of_Sixes(n, dice_rolls);
            printf(" You rolled:");
            for (i = 0; i < n; ++i)
            {
                printf(" %d ", dice_rolls[i]);
            }

        printf("\nWould you like to play again? Press 'y' for yes and 'n' for no.\n");
        scanf(" %c", &play_again);

    } while (play_again == 'y');

    printf("Thank you for playing yatzy!\n");

    free(dice_rolls);

return(0);
}

/* Denne funktion indkapsler de andre funktioner, som kører hele spillet. */
/*
void play_yatzy(int n)
{


}
*/

/* Denne funktion kaster n terninger. */
void roll_multiple_dies(int n, int dice_rolls[])
{
    int i = 0;

    for (i = 0; i < n; ++i)
    {
        dice_rolls[i] = rand() % DIE_MAX_EYES + 1;
    }  
}

/* Denne funktion skal finde og udskrive mit samlede antal 1'ere. */
void Number_of_Ones(int n, int dice_rolls[])
{
    int i = 0; 
    int score = 0; 

    roll_multiple_dies(n, dice_rolls);   

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == 1)
        {
            score = score + 1;
        }
    }  
    printf("\n|| Number of ones: %d   || Points this round: %d ||", score, score);
}

void Number_of_Twos(int n, int dice_rolls[])
{
    int i = 0; 
    int score = 0;

    roll_multiple_dies(n, dice_rolls);

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == 2)
        {
            score = score + 2;
        }
    }
    printf("\n|| Number of twos: %d   || Points this round: %d ||", (score / 2), score);
}

void Number_of_Threes(int n, int dice_rolls[])
{
    int i = 0; 
    int score = 0;
    
    roll_multiple_dies(n, dice_rolls);

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == 3)
        {
            score = score + 3;
        }
    }
    printf("\n|| Number of threes: %d || Points this round: %d ||", (score / 3), score);
}

void Number_of_Fours(int n, int dice_rolls[])
{
    int i = 0; 
    int score = 0;
    
    roll_multiple_dies(n, dice_rolls);

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == 4)
        {
            score = score + 4;
        }
    }
    printf("\n|| Number of fours: %d  || Points this round: %d ||", (score / 4), score);
}

void Number_of_Fives(int n, int dice_rolls[])
{
    int i = 0; 
    int score = 0;
    
    roll_multiple_dies(n, dice_rolls);

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == 5)
        {
            score = score + 5;
        }
    }
    printf("\n|| Number of fives: %d  || Points this round: %d ||", (score / 5), score);
}

void Number_of_Sixes(int n, int dice_rolls[])
{
    int i = 0; 
    int score = 0;
    
    roll_multiple_dies(n, dice_rolls);

    for (i = 0; i < n; ++i)
    {
        if (dice_rolls[i] == 6)
        {
            score = score + 6;
        }
    }
    printf("\n|| Number of sixes: %d  || Points this round: %d ||", (score / 6), score);
}