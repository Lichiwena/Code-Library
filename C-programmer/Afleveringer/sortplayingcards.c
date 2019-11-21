#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

enum color {Clubs = 1, Diamonds, Hearts, Spades, No_Color}
enum card_number {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
                  Jack = 11, Queen = 12, King = 13, Ace = 14, Joker = 15}

struct deck_of_cards
{
    int color;
    int card_number;
}
typedef struct deck_of_cards deck_of_cards; /* Her typedeffer jeg min struct til blot at hedde "deck_of_cards" fremover */

void Clear_Screen(void);

int main(void)
{
    deck_of_cards* card_game = 0;
    char play_again = 'a';

    do
    {
        Clear_Screen();
        printf("*** CARD SORT ***\n\n");
        printf("This program sorts a set of ordinary playing cards with 3 Jokers!\n");

        card_game = calloc(55, sizeof(deck_of_cards));

        printf("\nWould you like to play again? Press 'y' for yes and 'n' for no.\n");
        scanf(" %c", &play_again);

    } while (play_again == 'y');
    printf("Thanks for playing Card Sort!\n");

    return (0);
}

void Clear_Screen()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}