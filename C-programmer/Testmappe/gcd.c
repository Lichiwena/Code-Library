// Ein Programm, das den grosster gemeinsamer Teiler zweier Zahlen berechnet.

#include <stdio.h>

int main(void)
{
    int          a = 0,
                 b = 0,
             large = 0,
             small = 0,
        large_temp = 1,
        small_temp = 0;

    printf("Bitte zwei ganzen Zahlen grosser als 0 hier schreiben: \n");
    scanf( "%d %d", &a, &b);

    printf("Deine Eingabe ist %d und %d.\n\n", a, b);

    // Her finder jeg ud af, om a eller b er størst vha. en ternær operator og assigner til hhv. large og small.
    a > b ? (large = a) && (small = b) : (large = b) && (small = a);

    int division_number = 1;

    // Starter mit while loop, der skal tjekke, om det store tal % det lille tal (divideret til et mindre tal) er 0.
    // Når large_temp = 0, så slutter while loopet, og vi har fundet største fælles divisor.
    while (large_temp != 0)
    {
        small_temp = small / division_number;
        large_temp = large % small_temp;

        ++division_number;
    }

    printf("Die Zahl, die die beiden Zahlen a = %d und b = %d teilt, ist: %d \n", a, b, small_temp);

return (0);

}