#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH           6
#define MAX_CURRENT_STRING_LENGTH  60 /* 55 needed */
#define TOTAL_MATCHES             182
#define TOTAL_TEAMS                14

typedef struct
{
    char  day_of_week[MAX_STRING_LENGTH];
    char  date[MAX_STRING_LENGTH];
    char  time_of_match[MAX_STRING_LENGTH];
    char  home_team[MAX_STRING_LENGTH];
    char  away_team[MAX_STRING_LENGTH];
    int   home_team_score;
    int   away_team_score;
    int   spectators;
} match_struct; 

typedef struct
{
    char *team_name[4]; /* Max length of team name is 3 + \0 */
    int  points;
    int  goals_scored_by_team;
    int  goals_scored_vs_team;
    int  goal_difference;
} team_struct;

enum team_name {AaB = 1, ACH, AGF, BIF, EFB, FCK, FCM, FCN, HOB, OB, RFC, SDR, VB, VEN};

void fill_in_team_array(team_struct team_array, match_struct current_match);

int main(void)
{   
    FILE *filepointer = fopen("kampe2018-2019.txt", "r");
    int i = 0;
    match_struct match_array[TOTAL_MATCHES];
    char current_string[MAX_CURRENT_STRING_LENGTH];
    team_struct team_array[TOTAL_TEAMS];

    if (filepointer != NULL)
    {      
        /* fgets læser ind til MAX_CURRENT_STRING_LENGTH på 60 eller til den finder en new line. */
        /* While current_string != NULL står der basically                                       */
        while (fgets(current_string, MAX_CURRENT_STRING_LENGTH, filepointer) != NULL){
            sscanf(current_string, "%s %s %s %s - %s %d - %d %d",
                   match_array[i].day_of_week,
                   match_array[i].date,
                   match_array[i].time_of_match,
                   match_array[i].home_team,
                   match_array[i].away_team,
                   &match_array[i].home_team_score,
                   &match_array[i].away_team_score,
                   &match_array[i].spectators
                   );
            /* [i] skal stå efter match_array, da man i match array'et kigger efter f.eks.  */
            /* day_of_week på den i'de plads. F.eks. ville match_array[20].day_of_week være */
            /* day_of_week på den 20'ende plads i arrayet (linje 20 i txt filen)            */

            printf("%s %s %s %s - %s %d - %d %d\n",
                   match_array[i].day_of_week,
                   match_array[i].date,
                   match_array[i].time_of_match,
                   match_array[i].home_team,
                   match_array[i].away_team,
                   match_array[i].home_team_score,
                   match_array[i].away_team_score,
                   match_array[i].spectators );

            fill_in_team_array(team_array[i], match_array[i]);
        }
    } else {
        printf("Something went wrong. Your desired file was not found. Please try again.\n");
    }

    return (0);
}


void fill_in_team_array(team_struct team_array, match_struct current_match)
{
    printf("Int is: %d\n", current_match.home_team_score);
    printf("Char is: %s\n", current_match.home_team);

    switch ((int)current_match.home_team)
    {
        case (int)"AaB":
            printf("Vi ramte rigtigt\n");
        break;
        /*
        case "ACH":
        break;
        case "AGF":
        break;
        case BIF:
        break;
        case EFB:
        break;
        case FCK:
        break;
        case FCM:
        break;
        case FCN:
        break;
        case HOB:
        break;
        case  OB:
        break;
        case RFC:
        break;
        case SDR:
        break;
        case  VB:
        fill_in_team_struct("VB")
        break;
        case VEN:
        fill_in_team_struct("VEN")
        break; 
    */
    }
}
