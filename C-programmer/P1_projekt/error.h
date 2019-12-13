#include <stdio.h>
#include <stdlib.h>

int error(int errorNumber)
{

    switch (errorNumber)
    {
    case 1:
        printf("Error 101: Input er ikke gyldigt, proev igen! \n");
        break;
    case 2:
        printf("Error 102: Ikke nok plads tilgaengelig! \n");
        break;
    case 3:
        printf("Error 103: Tekstdokument ikke tilgaengelig! \n");
        break;
    case 4:
        printf("Error 104: Database er ikke tilgaengelig! \n");
        break;
    case 5:
        printf("Error 105: Fejl ved indlaesning af database! \n");
        break;
    case 6:
        printf("Error 106: Fejl ved indlaesning af tekstdokument! \n");
        break;
    case 7:
        printf("Error 107: For mange ingredienser \n");
        break;
    }
    return 0;
}