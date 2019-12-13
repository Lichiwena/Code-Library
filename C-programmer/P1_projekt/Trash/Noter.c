Noter til P1 program;

int count_index_number
Den læser ind til efter lighedstegn = og gemmer den værdi. Den gemmer altså indexnumber.
Derefter læser den til hver new line.
Til sidst returnerer den antal retter +1, da den tæller 30 (men arrayet starter på 0), så der er 30+1.

int user_settings
fflush clearer inputbufferen eller noget i den stil. Hvis du har promptet for et j/n, og useren skriver n, så vil fflush fjerne dette n.

int read_settings
Læser settings.

void make_ingredients
Scanner database.ingredients på current indexnumber. Gemmes i en variabel localName, localAmount og localUnit. 
&localAmount har en ampersand, fordi det er en double.

Wipe funktion: Hvis der ikke er 7 ingredienser i en ret, så vil de gamle ingredienser blive gemt. F.eks. i Ret 2, så er der kun 2 ingredienser.
Så er de gamle ingredienser for 3, 4, 5, 6, og 7 gemt i denne. Derfor skal de wipes med denne funktion. clear sætter bare ting til mellemrum.
strcpy(localName[wipe]) = clear = den første string (ingrediens navn) wipes og sættes til mellemrum. Doublen sættes til 0. Den sidste string sættes også til mellemrum.

void print_grocery_list
Comparer Opskrift 1 og Opskrift 2s første elementer. Hvis navnene er de samme (stringcopy er 0), så adderes amount sammen.
Tallet 8 er hardcoded fordi det virker. Indkøbslisten kombinerer ikke tingene alligevel.
Måske er det fordi, den kun komparer Ingrediens nr. 1 i Opskrift 1 med Ingrediens nr. 1 i Opskrift 2. Den comparer måske ikke med alle.

