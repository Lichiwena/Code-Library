#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LGT 50

typedef struct {
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
} person;

int main(void)
{
    FILE *ifp = fopen("adresser.txt", "r");
    person person_array[50];
    char *current_string = (char*)calloc(200, sizeof(char));
    int i = 0;

    if (ifp != NULL){
            current_string = fgets(current_string, 200, ifp);
            while (*(current_string) != EOF)
            {
                sscanf(current_string,
                " %[a-zA-Z]"
                " %[a-zA-Z],"
                " %[^0-9]"
                " %d,"
                " %d"
                " %[a-zA-Z].",
                person_array[i].fornavn,
                person_array[i].efternavn,
                person_array[i].vejnavn,
                &person_array[i].vejnummer,
                &person_array[i].postnummer,
                person_array[i].bynavn
                );
            printf("current_string: %s\n", current_string);
            printf("Fornavn: %s, Efternavn; %s, Vejnavn: %s, Vejnummer: %d, Postnummer: %d, Bynavn: %s.\n",
                person_array[i].fornavn,
                person_array[i].efternavn,
                person_array[i].vejnavn,
                person_array[i].vejnummer,
                person_array[i].postnummer,
                person_array[i].bynavn
                );
        ++i;
        current_string = fgets(current_string, 200, ifp);
            }
        }else {
            printf("Couldn't open your document. Please try again.\n");            
        }

    qsort(person_array, 50, sizeof(person), element_compare);

    printf("By          | Navn\n");
    printf("%14s| %14s\n", person_array[i].bynavn, person_array[i].efternavn);

return (0);
}


int element_compare(const void* a, const void* b)
{
    return (*(person)a->efternavn - *(person)b->efternavn);
}
