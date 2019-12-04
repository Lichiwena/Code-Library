#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH           6
#define MAX_CURRENT_STRING_LENGTH  60 /* 55 needed */
#define TOTAL_MATCHES             182
#define TOTAL_TEAMS                14
#define HOME                        1
#define AWAY                        0

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
    char team_name[4]; /* Max length of team name is 3 + \0 */
    int  points;
    int  goals_scored_by_team;
    int  goals_scored_vs_team;
    int  goal_difference;
} team_struct;

enum team_name {AaB_index = 0, ACH_index, AGF_index, BIF_index, EFB_index, FCK_index, FCM_index,
                FCN_index, HOB_index, OB_index, RFC_index, SDR_index, VB_index, VEN_index};

void fill_in_team_array(team_struct team_array[], match_struct current_match, int is_home, char *team_name);
void update_team_score(team_struct team_array[], match_struct current_match, int is_home, int team_index);
int match_result(int team_a_goals, int team_b_goals);
void fill_in_team_name(team_struct team_array[], char *team_name, int team_index);

int main(void)
{   
    int i = 0;
    FILE *filepointer = fopen("kampe2018-2019.txt", "r");
    match_struct match_array[TOTAL_MATCHES];
    char current_string[MAX_CURRENT_STRING_LENGTH];
    team_struct team_array[20]; /* REE */

    if (filepointer != NULL)
    {      
        /* f get s == file get string                                                            */
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
            ++i;
        }
    } else {
        printf("Something went wrong. Your desired file was not found. Please try again.\n");
    }

    for (i = 0; i < TOTAL_MATCHES; ++i)
    {
        /* Håndterer home team */
        fill_in_team_array(team_array, match_array[i], HOME, match_array[i].home_team);

        /* Håndterer away team */
        fill_in_team_array(team_array, match_array[i], AWAY, match_array[i].away_team);
    }

    for (i = 0; i < TOTAL_TEAMS; ++i)
    {
        printf("| Name: %4s | Points %4d | Scored by team: %4d | Scored vs team: %4d | Goal difference: %4d |\n",
                team_array[i].team_name,
                team_array[i].points,
                team_array[i].goals_scored_by_team,
                team_array[i].goals_scored_vs_team,
                team_array[i].goal_difference
                );
    }
    fclose(filepointer);

    return (0);
}

void fill_in_team_array(team_struct team_array[], match_struct current_match, int is_home, char *team_name)
{
   if (strcmp("AaB", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, AaB_index);
        fill_in_team_name(team_array, team_name, AaB_index);

   } else if (strcmp("ACH", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, ACH_index);
        fill_in_team_name(team_array, team_name, ACH_index);

   } else if (strcmp("AGF", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, AGF_index);
        fill_in_team_name(team_array, team_name, AGF_index);

   } else if (strcmp("BIF", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, BIF_index);
        fill_in_team_name(team_array, team_name, BIF_index);

   } else if (strcmp("EFB", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, EFB_index);
        fill_in_team_name(team_array, team_name, EFB_index);

   } else if (strcmp("FCK", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, FCK_index);
        fill_in_team_name(team_array, team_name, FCK_index);

   } else if (strcmp("FCM", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, FCM_index);
        fill_in_team_name(team_array, team_name, FCM_index);

   } else if (strcmp("FCN", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, FCN_index);
        fill_in_team_name(team_array, team_name, FCN_index);

   } else if (strcmp("HOB", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, HOB_index);
        fill_in_team_name(team_array, team_name, HOB_index);

   } else if (strcmp("OB", team_name) == 0)  {
        update_team_score(team_array, current_match, is_home, OB_index);
        fill_in_team_name(team_array, team_name, OB_index);

   } else if (strcmp("RFC", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, RFC_index);
        fill_in_team_name(team_array, team_name, RFC_index);

   } else if (strcmp("SDR", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, SDR_index);
        fill_in_team_name(team_array, team_name, SDR_index);

   } else if (strcmp("VB", team_name) == 0)  {
        update_team_score(team_array, current_match, is_home, VB_index);
        fill_in_team_name(team_array, team_name, VB_index);

   } else if (strcmp("VEN", team_name) == 0) {
        update_team_score(team_array, current_match, is_home, VEN_index);
        fill_in_team_name(team_array, team_name, VEN_index);
    }
}

/* Hvis is_home = 1, så er det fordi, holdet er hjemmebane. Hvis is_home = 0, så er det fordi holdet er */
/* udebane. Herefter opdateres goals_scored_by_team, goals_scored_vs_team og goal_difference alt efter, */
/* om holdet er ude eller hjemme. (Det er samme funktion med med "home" eller "away").                  */
void update_team_score(team_struct team_array[], match_struct current_match, int is_home, int team_index)
{
    if (is_home == 1)
    {
        team_array[team_index].points               += match_result(current_match.home_team_score, current_match.away_team_score);
        team_array[team_index].goals_scored_by_team += current_match.home_team_score;
        team_array[team_index].goals_scored_vs_team += current_match.away_team_score;
        team_array[team_index].goal_difference      += (current_match.home_team_score - current_match.away_team_score);

    } else if (is_home == 0)
    {
        team_array[team_index].points               += match_result(current_match.away_team_score, current_match.home_team_score);
        team_array[team_index].goals_scored_by_team += current_match.away_team_score;
        team_array[team_index].goals_scored_vs_team += current_match.home_team_score;
        team_array[team_index].goal_difference      += (current_match.away_team_score - current_match.home_team_score);   
    }
}

int match_result(int team_a_goals, int team_b_goals)
{
    int result = 0;

    if (team_a_goals > team_b_goals)
    {
        result = 3;
    } else if (team_a_goals == team_b_goals)
    {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

void fill_in_team_name(team_struct team_array[], char *team_name, int team_index)
{
    if (strcmp(team_array[team_index].team_name, team_name) != 0)
    {
        strcpy(team_array[team_index].team_name, team_name);
    }
}