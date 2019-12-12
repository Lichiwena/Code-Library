#include <stdio.h>
#include <stdlib.h>

int error(int errorNumber)
{

    switch (errorNumber)
    {
    case 1:
        printf("Error 101: Input er ikke gyldigt, prøv igen! \n");
        break;
    case 2:
        printf("Error 102: Ikke nok plads tilgængelig! \n");
        break;
    case 3:
        printf("Error 103: Tekstdokument ikke tilgængelig! \n");
        break;
    case 4:
        printf("Error 104: Database er ikke tilgængelig! \n");
        break;
    case 5:
        printf("Error 105: Fejl ved indlæsning af database! \n");
        break;
    case 6:
        printf("Error 106: Fejl ved indlæsning af tekstdokument! \n");
        break;
    case 7:
        printf("Error 107: For mange ingredienser \n");
        break;
    }
    return 0;
}