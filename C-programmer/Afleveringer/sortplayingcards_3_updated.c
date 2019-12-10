#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER_OF_CARDS 55

typedef struct /* Her typedeffer jeg min struct til blot at hedde "deck_of_cards" fremover */
{
    int color;
    int card_number;
} deck_of_cards;

enum color {Clubs = 1, Diamonds, Hearts, Spades, No_color};
enum card_number {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
                  Jack = 11, Queen = 12, King = 13, Ace = 14, Joker = 15};

void Clear_Screen(void);
deck_of_cards generate_card_struct (int color, int i);
void fill_in_cards (deck_of_cards card_game_array[]);
void fill_in_Jokers (deck_of_cards card_game_array[]);
void print_cards(deck_of_cards card_game_array[]);
void print_Jokers(deck_of_cards card_game_array[]);
void print_new_line(void);
char *convert_color_to_string(int color);
char *convert_card_number_to_string(int card_number);
void randomize_cards(deck_of_cards* card_game_array);
void sort_cards(deck_of_cards* card_game_array);
int element_compare_color(const void *color_a, const void *color_b);
int element_compare_random(const void *ip1, const void *ip2);

int main(void)
{
    deck_of_cards* card_game_array = NULL;

    srand(time(NULL));

    Clear_Screen();
    printf("*** CARD SORT ***\n\n");
    printf("This program sorts a set of ordinary playing cards with 3 Jokers!\n");

    card_game_array = calloc(MAX_NUMBER_OF_CARDS, sizeof(deck_of_cards));

    fill_in_cards(card_game_array);
    fill_in_Jokers(card_game_array);
    
    print_new_line();
    printf("These are the unsorted cards:");
    print_new_line();
    randomize_cards(card_game_array);
    print_new_line();
    printf("These are the sorted cards:");
    print_new_line();
    sort_cards(card_game_array);

    printf("Thanks for playing Card Sort!\n");

    free(card_game_array);

    return (0);
}

/* Denne funktion genererer mine kort i et struct. */
deck_of_cards generate_card_struct (int color, int i)
{
    deck_of_cards generated_card;

    generated_card.color = color;
    generated_card.card_number = i;

    return generated_card;
}

void fill_in_cards (deck_of_cards card_game_array[])
{
    int i = 0;
    for (i = 0; i <= 13; ++i) /* All Clubs, Diamonds, Hearts and Spades */
    {
        card_game_array[i     ] = generate_card_struct(1, (i + 2));
        card_game_array[i + 13] = generate_card_struct(2, (i + 2));
        card_game_array[i + 26] = generate_card_struct(3, (i + 2));
        card_game_array[i + 39] = generate_card_struct(4, (i + 2));
    }
}

void fill_in_Jokers (deck_of_cards card_game_array[])
{
    int i = 14; /* Fills in all Jokers */

    card_game_array[i + 38] = generate_card_struct(5, (i + 1));
    card_game_array[i + 39] = generate_card_struct(5, (i + 1));
    card_game_array[i + 40] = generate_card_struct(5, (i + 1));
}

/* Denne funktion printer mine kort fra 1-52. */
void print_cards(deck_of_cards card_game_array[])
{
    int i = 1;

    for (i = 0; i < (MAX_NUMBER_OF_CARDS - 3); ++i)
    {
        if (card_game_array[i].color != 5)
        {
            printf("Card is: %s of %s\n",
            convert_card_number_to_string(card_game_array[i].card_number),
            convert_color_to_string(card_game_array[i].color));

        } else {
            printf("Card is: %s %s\n",
            convert_card_number_to_string(card_game_array[i].card_number),
            convert_color_to_string(card_game_array[i].color));           
        }
    }
}

/* Denne funktion printer de kort, som er på de tre sidste pladser. Det
   vil sige jokerne i det sorterede array, herfra navnet "print_Jokers".
   (Selvom det ikke nødvendigvis er jokere i det usorterede array). */
void print_Jokers(deck_of_cards card_game_array[])
{
    int i = 1;

    for (i = 52; i < MAX_NUMBER_OF_CARDS; ++i)
    {
        if (card_game_array[i].color != 5)
        {
            printf("Card is: %s of %s\n",
            convert_card_number_to_string(card_game_array[i].card_number),
            convert_color_to_string(card_game_array[i].color));

        } else {
            printf("Card is: %s %s\n",
            convert_card_number_to_string(card_game_array[i].card_number),
            convert_color_to_string(card_game_array[i].color));           
        }
    }
}

/* Printer ny linje i min oversigt. */
void print_new_line(void)
{
    printf("\n--------------------------\n");
}

/* Denne funktion switcher på color_number (color fra min struct),
   og oversætter nummeret til en string. F.eks., hvis color er 1,
   som i min enum er lavet til "Clubs", så returneres "Clubs".     */
char *convert_color_to_string(int color)
{
    char* color_number_as_string = (char *)calloc(8, sizeof(char));

    switch (color)
    {
        case Clubs:
            color_number_as_string = "Clubs";
        break;
        case Diamonds:
            color_number_as_string = "Diamonds";
        break;
        case Hearts:
            color_number_as_string = "Hearts";
        break;
        case Spades:
            color_number_as_string = "Spades";
        break;
        case No_color:
            color_number_as_string = "";
        break;
    }
    
    free(color_number_as_string);

    return color_number_as_string;
}

/* Denne funktion gør det samme som ovenstående funktion, men med
   card_number i stedet for. */
char *convert_card_number_to_string(int card_number)
{
    char* card_number_as_string = (char *)calloc(8, sizeof(char));

    switch (card_number)
    {
        case Two:
            card_number_as_string = "Two";
        break;
        case Three:
            card_number_as_string = "Three";
        break;
        case Four:
            card_number_as_string = "Four";
        break;
        case Five:
            card_number_as_string = "Five";
        break;
        case Six:
            card_number_as_string = "Six";
        break;
        case Seven:
            card_number_as_string = "Seven";
        break;
        case Eight:
            card_number_as_string = "Eight";
        break;
        case Nine:
            card_number_as_string = "Nine";
        break;
        case Ten:
            card_number_as_string = "Ten";
        break;
        case Jack:
            card_number_as_string = "Jack";
        break;
        case Queen:
            card_number_as_string = "Queen";
        break;
        case King:
            card_number_as_string = "King";
        break;
        case Ace:
            card_number_as_string = "Ace";
        break;
        case Joker:
            card_number_as_string = "Joker";
        break;
    }

    free(card_number_as_string);

    return card_number_as_string;
}

/* Denne funktion randomizer mine kort ved at bruge den random
   element compare funktion. Den random rækkefølge af kort printes. */
void randomize_cards(deck_of_cards* card_game_array)
{
    qsort(card_game_array, MAX_NUMBER_OF_CARDS, sizeof(deck_of_cards), element_compare_random);

    print_cards(card_game_array);
    print_Jokers(card_game_array);
}

/* Denne funktion sorterer mine kort og printer dem herefter. */
void sort_cards(deck_of_cards* card_game_array)
{
    qsort(card_game_array, MAX_NUMBER_OF_CARDS, sizeof(deck_of_cards), element_compare_color);

    print_cards(card_game_array);
    print_Jokers(card_game_array);
}

/* Kurts element compare funktion, men randomized. */
int element_compare_random(const void *ip1, const void *ip2)
{
    int result = 0;

    if (rand() < (RAND_MAX / 2))
        result = -1;
    else if (rand() > (RAND_MAX / 2))
        result = 1;
    else
        result = 0;

    return result;
}

int element_compare_color(const void *color_a, const void *color_b)
{
    int result = 0;

    deck_of_cards *deck_of_cards_a = (deck_of_cards *)color_a;
    deck_of_cards *deck_of_cards_b = (deck_of_cards *)color_b;

    if(deck_of_cards_a->color == deck_of_cards_b->color){
        result = (deck_of_cards_a->card_number - deck_of_cards_b->card_number);
    } else {
        result = (deck_of_cards_a->color - deck_of_cards_b->color);
    }

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
