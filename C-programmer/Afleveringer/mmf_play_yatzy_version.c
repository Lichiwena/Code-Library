#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIE_MAX_EYES 6
#define MAX_SELECT 5
#define BONUS_LIMIT ( 3 * ( 1 + 2 + 3 + 4 + 5 + 6 ) )

/* Declare functions */
void Clear_Screen();
void Roll_Multiple_Dies(int n, int dice_rolls[]);
int Find_Numbers_One_to_Six(int n, int dice_rolls[], int number_I_want_to_find);
int Calculate_Bonus(int num_dice, int total_score);
int Find_One_Pair(int n, int dice_rolls[]);
int Find_One_Pair(int n, int dice_rolls[]);
int Find_Two_Pairs(int n, int dice_rolls[]);
int Find_Three_of_a_Kind(int n, int dice_rolls[]);
int Find_Four_of_a_Kind(int n, int dice_rolls[]);
int Check_for_Small_Straight(int n, int dice_rolls[]);
int Check_for_Big_Straight(int n, int dice_rolls[]);
int Check_for_Full_House(int n, int dice_rolls[]);
int Find_Chance(int n, int dice_rolls[]);
int Check_for_Yatzy(int n, int dice_rolls[]);
int element_compare(const void *ip1, const void *ip2);

/* Begin of main program */
int main(void)
{
	/* Define global variables named with prefix g_ */
    int  g_num_dice = 0,      // Number of dice to use in play entered by user
         g_total_score = 0;   // Total score for a complete set of rounds
    int *g_dice_rolls = 0;    // Pointer to array of integers for dice rolls
    char g_play_again = 'a';  // Initial value for play again Y/N

    srand(time(NULL));

    /* Min do-while løkke kører mindst én gang, og så længe g_play_again == y, så kører løkken.*/
    do {
		Clear_Screen();
		printf("*** PLAY YATZY ***\n\n");
        g_total_score = 0;   // Reset total score
		
        printf("Please enter the number of dies you would like to play with: ");
        scanf(" %d", &g_num_dice);
        while (g_num_dice < MAX_SELECT)
        {
            printf("Please enter a number that is 5 or higher: ");
            scanf(" %d", &g_num_dice);
        }
        printf("\n");

        /* Her allokeres space til mit array via calloc og pladsen assignes til arrayet g_dice_rolls. */
        g_dice_rolls = calloc(g_num_dice, sizeof(int));

        for (int number_I_want_to_find = 1; number_I_want_to_find <= 6; ++number_I_want_to_find)
        {
            g_total_score = g_total_score + Find_Numbers_One_to_Six(g_num_dice, g_dice_rolls, number_I_want_to_find);
        }
        g_total_score = g_total_score + Calculate_Bonus(g_num_dice, g_total_score);
		
        g_total_score = g_total_score + Find_One_Pair(g_num_dice, g_dice_rolls);
        g_total_score = g_total_score + Find_Two_Pairs(g_num_dice, g_dice_rolls);
        g_total_score = g_total_score + Find_Three_of_a_Kind(g_num_dice, g_dice_rolls);
        g_total_score = g_total_score + Find_Four_of_a_Kind(g_num_dice, g_dice_rolls);
        g_total_score = g_total_score + Check_for_Small_Straight(g_num_dice, g_dice_rolls);
        g_total_score = g_total_score + Check_for_Big_Straight(g_num_dice, g_dice_rolls);
        g_total_score = g_total_score + Check_for_Full_House(g_num_dice, g_dice_rolls);
        g_total_score = g_total_score + Find_Chance(g_num_dice, g_dice_rolls);
        g_total_score = g_total_score + Check_for_Yatzy(g_num_dice, g_dice_rolls);

		// Display BONUS line
		printf("|| ");    
		for (int i = 0; i < g_num_dice; ++i)
			printf("  ");
		printf("|| TOTAL            : %4d ||\n", g_total_score);
		
		printf("\nWould you like to play again? Press 'y' for yes or 'n' for no: ");
		scanf(" %c", &g_play_again);

    } while (g_play_again == 'y');
    printf("Thank you for playing yatzy!\n\n");

    free(g_dice_rolls);

	return(0);
}
/* End of main program */


/* Denne funktion kaster n terninger. */
void Roll_Multiple_Dies(int n, int dice_rolls[])
{
    for (int i = 0; i < n; ++i)
    {
        dice_rolls[i] = rand() % DIE_MAX_EYES + 1;
    }  
}

/* Denne funktion kører de første 6 runder af spillet. */
int Find_Numbers_One_to_Six(int num_dice, int dice_rolls[], int number_I_want_to_find)
{
    int score = 0,
	    selected = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);   

    /* Kører i op fra 0 til én mindre end 5.
    Hvis tallet i mit array (starter med tallet med index 0) er det tal,
    jeg gerne vil finde (1 for første gennemgang), så tælles score op med
    det tal jeg gerne vil finde (altså 1 ved første gennemgang). Ellers
    gemmes tallet ikke. */
    for (int i = 0; i < num_dice; ++i)
    {
        if (dice_rolls[i] == number_I_want_to_find)
        {
            score = score + number_I_want_to_find;
			selected = selected + 1;
			if (selected == MAX_SELECT)
				i = num_dice; // break out of for loop
        }
    }  
    
    printf("|| "); 
    
    /* Her printes værdierne i arrayet ud vha. en forløkke. */
    for (int i = 0; i < num_dice; ++i)
        {
            printf("%d ", dice_rolls[i]);
        }
    printf("|| Points this round: %4d ||\n", score);
	return score;
	}

int Calculate_Bonus(int num_dice, int total_score)
{
    int score = 0;

	// Display SUM line
    printf("|| ");    
    for (int i = 0; i < num_dice; ++i)
       printf("  ");
    printf("|| SUM              : %4d ||\n", total_score);

	if (total_score >= BONUS_LIMIT)
		score = 50;

	// Display BONUS line
    printf("|| ");    
    for (int i = 0; i < num_dice; ++i)
       printf("  ");
    printf("|| BONUS            : %4d ||\n", score);
	
    printf("\n");

	return score;
}
	
/* Denne funktion finder et par. Først bruges qsort til at sortere 
   elementerne fra mindste element til største element, dernæst
   sammenlignes de to største elementer. Hvis disse er lig hinanden,
   er der et par. Hvis ikke, kører man ned gennem rækken, til der 
   findes det største par i rækken. */
int Find_One_Pair(int num_dice, int dice_rolls[])
{
    int score = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    qsort(dice_rolls, num_dice, sizeof(int), element_compare);

    printf("|| ");
    for (int i = 0; i < num_dice; ++i)
        {
            printf("%d ", dice_rolls[i]);
        }
//    printf(" ||");

    /* Yoinket fra stackoverflow, men reversed */
    /* Hvis de sidste to elementer i mit array er ens, så printes det
    højeste par ud. Hvis ikke, så tælles i ned med 1, så men tjekker
    næste to elementer i rækken. Hvis de to elementer er ens,
    sættes i til 0, og forløkken stopper, så den ikke skal finde
    flere par (da vi kun vil finde det højeste par).*/
    for (int i = (num_dice - 1); i > 0; --i)
        {
            if(dice_rolls[i] == dice_rolls[i - 1])
            {
// OLD          score = score + dice_rolls[i] * 2;
                score =         dice_rolls[i] * 2;
                i = 0;
            }
        }
    printf("|| Points this round: %4d ||\n", score);
	return score;
}

int Find_Two_Pairs(int num_dice, int dice_rolls[])
{
    int pairs = 0,
        block_same_pair = 0,
        score = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    qsort(dice_rolls, num_dice, sizeof(int), element_compare);

    printf("|| ");
    for (int i = 0; i < num_dice; ++i)
        {
            printf("%d ", dice_rolls[i]);
        }
//    printf(" ||");

    /* Scoren tælles op hver gang, der findes et par, med øjnene på
    terningen (f.eks. 6) ganget med to (da det er et par). Til sidst
    printes scoren. */
    for (int i = (num_dice - 1); i > 0; --i)
        {
//OLD       if (dice_rolls[i] == dice_rolls[i - 1] && (pairs < 2) && (dice_rolls[i] != block_same_pair))
            if (dice_rolls[i] == dice_rolls[i - 1]                &&  dice_rolls[i] != block_same_pair )
            {
                block_same_pair = dice_rolls[i];
                score = score + (dice_rolls[i] * 2);
                ++pairs;              
            }
            
            if (pairs == 2)
                i = 0;
        }
    /* If we did not find two pairs reset score to zero */
    if (pairs != 2)
        score = 0;

    printf("|| Points this round: %4d ||\n", score);
	return score;
}

int Find_Three_of_a_Kind(int num_dice, int dice_rolls[])
{
    int score = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    qsort(dice_rolls, num_dice, sizeof(int), element_compare);

    printf("||");
    for (int i = 0; i < num_dice; ++i)
        {
            printf(" %d", dice_rolls[i]);
        }
    printf(" ||");

    /* i >= 2 - Men HVORFOR 2? Fordi, hvis den er nået til elementet på
    index 2, så sammenligner den med index 0, som er det sidste element
    tilbage i array'et. Den kan ikke blive lavere end 2, fordi så 
    sammenlignes der med et element, som ikke findes i array'et. */
    for (int i = (num_dice - 1); i >= 2; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 2]) /* Hvis index num_dice-1 er lig med den, der er to pladser længere til venstre, så TRUE. */
        {
            score = (dice_rolls[i] * 3);
            i = 0;
        }
    } 
    printf(" Points this round: %4d ||\n", score);
	return score;
}

int Find_Four_of_a_Kind(int num_dice, int dice_rolls[])
{
    int score = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    qsort(dice_rolls, num_dice, sizeof(int), element_compare);

    printf("||");
    for (int i = 0; i < num_dice; ++i)
        {
            printf(" %d", dice_rolls[i]);
        }
    printf(" ||");

    for (int i = (num_dice - 1); i >= 3; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 3]) 
        {
            score = (dice_rolls[i] * 4);
            i = 0;
        }
    } 
    printf(" Points this round: %4d ||\n", score);
	return score;
}

int Check_for_Small_Straight(int num_dice, int dice_rolls[])
{
    int i = 0,
        score = 0,
        found_one = 0,
        found_two = 0,
        found_three = 0,
        found_four = 0,
        found_five = 0,
        found_small_straight = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    printf("||");
    for (int i = 0; i < num_dice; ++i)
        {
            printf(" %d", dice_rolls[i]);
        }
    printf(" ||");

    for (int i = 0; i < num_dice; ++i)
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
            i = num_dice;
        }
    }
    printf(" Points this round: %4d ||\n", score);
	return score;
}

int Check_for_Big_Straight(int num_dice, int dice_rolls[])
{
    int score = 0,
        found_two = 0,
        found_three = 0,
        found_four = 0,
        found_five = 0,
        found_six = 0,
        found_big_straight = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    printf("||");
    for (int i = 0; i < num_dice; ++i)
        {
            printf(" %d", dice_rolls[i]);
        }
    printf(" ||");

    for (int i = 0; i < num_dice; ++i)
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
            i = num_dice;
        }
    }
    printf(" Points this round: %4d ||\n", score);
	return score;
}

int Check_for_Full_House(int num_dice, int dice_rolls[])
{
    int i = 0,
        score = 0,
        three_of_a_kind_number = 0,
        found_a_pair = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    qsort(dice_rolls, num_dice, sizeof(int), element_compare);

    printf("||");
    for (int i = 0; i < num_dice; ++i)
        {
            printf(" %d", dice_rolls[i]);
        }
    printf(" ||");
    
    for (int i = (num_dice - 1); i >= 2; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 2]) /* Hvis index num_dice-1 er lig med den, der er to pladser længere til venstre, så TRUE. */
        {
            three_of_a_kind_number = dice_rolls[i];
            score = score + (dice_rolls[i] * 3);
            i = 0;
        }
    } 

    if (score != 0)
    {
        for (int i = (num_dice - 1); i > 0; --i)
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
	return score;
}

int Find_Chance(int num_dice, int dice_rolls[])
{
    int score = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    qsort(dice_rolls, num_dice, sizeof(int), element_compare);

    printf("||");
    for (int i = 0; i < num_dice; ++i)
        {
            printf(" %d", dice_rolls[i]);
        }
    printf(" ||");

    /* i skal være (num_dice - 1), da det er det tal med højest index, altså
    det første i rækken fra højre. For-løkken skal køre for i > (n - 6),
    da dette er det 5. tal fra højre, som jo er de tal, vi skal bruge.
    Derfor køres for-løkken 5 gange. */
    for (int i = (num_dice - 1); i > (num_dice - 6); --i)
    {
        /* Scoren tælles op med det pågældende antal 
        øjne på terningen, for hver gang, for-loopet kører. */
        score = score + dice_rolls[i]; 
    }
	printf(" Points this round: %4d ||\n", score);
	return score;
}

/* Denne funktion finder ud af, om der er 5 ens vha. qsort. */
int Check_for_Yatzy(int num_dice, int dice_rolls[])
{
    int score = 0;

    Roll_Multiple_Dies(num_dice, dice_rolls);

    qsort(dice_rolls, num_dice, sizeof(int), element_compare);

    printf("||");
    for (int i = 0; i < num_dice; ++i)
        {
            printf(" %d", dice_rolls[i]);
        }
    printf(" ||");

    for (int i = (num_dice - 1); i > 4; --i)
    {
        if (dice_rolls[i] == dice_rolls[i - 4]) 
        {
            score = 50 + (dice_rolls[i] * 5);
            i = 0;
        }
    } 
    printf(" Points this round: %4d ||\n", score);
	return score;
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

void Clear_Screen(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
