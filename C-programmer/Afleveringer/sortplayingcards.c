#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum color {Clubs = 1, Diamonds, Hearts, Spades, No_Color};
enum card_number {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
                  Jack = 11, Queen = 12, King = 13, Ace = 14, Joker = 15};

typedef struct /* Her typedeffer jeg min struct til blot at hedde "deck_of_cards" fremover */
{
    int color;
    int card_number;
} deck_of_cards;

void Clear_Screen(void);
int element_compare(const void *ip1, const void *ip2);
void sort_cards(deck_of_cards, deck_of_cards card_game_array[]);

int main(void)
{
    deck_of_cards* card_game_array = 0;
    char play_again = 'a';

    do {
        Clear_Screen();
        printf("*** CARD SORT ***\n\n");
        printf("This program sorts a set of ordinary playing cards with 3 Jokers!\n");

        /* Her allokeres plads til mit card_game_array array. Denne får 55 pladser
           og det bliver at størrelsen af mit struct.                        */
        card_game_array = calloc(55, sizeof(deck_of_cards));

        sort_cards(deck_of_cards, card_game_array);

        printf("\nWould you like to play again? Press 'y' for yes and 'n' for no.\n");
        scanf(" %c", &play_again);

    } while (play_again == 'y');
    printf("Thanks for playing Card Sort!\n");

    free(card_game_array);

    return (0);
}

void sort_cards(deck_of_cards, deck_of_cards card_game_array[])
{
    int i = 0;

    qsort(card_game_array, 55, sizeof(deck_of_cards), element_compare);

    for (i = 0; i <= 55; ++i)
    {
        printf("Card is: %s of %s.\n", card_game_array[i].color,
                card_game_array[i].card_number);
    }
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

/* Denne funktion clearer terminalen. */
void Clear_Screen()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}