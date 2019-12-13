/*Defines brugt til simple ændringer*/
#define FALSE 0
#define TRUE 1
#define MAX_CHAR_LENGTH 140
#define MAX_ARRAY_LENGTH 50

struct settings{
    int vegan;
    int vegetarian;
    int price;
} settings;

/*Struct til at "lave" ingredinser i funktionen make_ingridents()*/
typedef struct ingredients{
    char name[MAX_CHAR_LENGTH];
    double amount;
    char unit[MAX_CHAR_LENGTH];
} ingredients;

/*Struct til at læse fra databasen, brugt hovedesaglig i read_data()*/
struct database{
    int *indexNumber;
    char **title;
    char **description;
    char **ingredients;
    int *vegetarian;
    int *vegan;
    int *price;
    int *time;
}database;

/*Prototyper*/
int count_index_numbers(FILE *input);
int** count_chars_title_description_ingridients(int numberOfRecipes, FILE *input);
void user_settings(FILE *usersettings, int numberOfRecipes);
void read_settings(FILE *psettingsFile);
void read_data(FILE *input, int databaseIndex);
void menu(FILE *psettingsFile, int numberOfRecipes);
void make_ingredients(int databaseIndex, int ingredientsIndex);
void print_grocery_list(FILE *shoppingList, ingredients ingredientsArray[MAX_ARRAY_LENGTH][MAX_CHAR_LENGTH]);
void print_meal_plan(FILE *output, int weekdayIndex, int databaseIndex, int numberOfRecipes);
void print_vegetarian_meal_plan();
void print_vegan_meal_plan(FILE *output, int weekdayIndex, int databaseIndex, int numberOfRecipes);
void print_standard_meal_plan(FILE *output, int weekdayIndex, int databaseIndex);
int satisfied_with_mealplan(FILE *output, int numberOfRecipes);
int find_new_dish(char krit1[], char krit2[], int numberOfRecipes);