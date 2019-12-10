/*Defines brugt til simple ændringer*/
#define FALSE 0
#define TRUE 1
#define MAX_CHAR_LENGTH 140
#define MAX_ARRAY_LENGTH 50

struct settings
{
    int vegan;
    int vegetarian;
    int price;
}settings;


/*Struct til at "lave" ingredinser i funktionen make_ingridents()*/
typedef struct ingredients{
    char name[MAX_CHAR_LENGTH];
    double amount;
    char unit[MAX_CHAR_LENGTH];
}ingredients;

/*Struct til at læse fra databasen, brugt hovedesaglig i read_data()*/
struct database{
    int  indexNumber[MAX_ARRAY_LENGTH];
    char title[MAX_ARRAY_LENGTH][MAX_CHAR_LENGTH];
    char description[MAX_ARRAY_LENGTH][1000];
    char ingredients[MAX_ARRAY_LENGTH][MAX_CHAR_LENGTH];
    int  vegetarian[MAX_CHAR_LENGTH];
    int  vegan[MAX_CHAR_LENGTH];
    int  price[MAX_ARRAY_LENGTH];
    int  time[MAX_ARRAY_LENGTH];
}database;

/*Prototyper*/
void user_settings(FILE *usersettings);
void read_settings(FILE *psettingsFile);
void read_data(FILE *input, int databaseIndex);
void make_ingredients(int databaseIndex, int ingredientsIndex);
void print_grocery_list(FILE *shoppingList , ingredients ingredientsArray[MAX_ARRAY_LENGTH][MAX_CHAR_LENGTH]);
void print_meal_plan(FILE *output, int weekdayIndex, int databaseIndex);
int myCompare(const void *ingredient_a, const void *ingredient_b);