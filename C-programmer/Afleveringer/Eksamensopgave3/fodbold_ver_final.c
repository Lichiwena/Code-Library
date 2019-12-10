/* Navn: Sarah Mølleskov Frandsen   *
 * Email: sfrand19@student.aau.dk   *
 * Gruppe: DAT A311                 *
 * Studieretning: Datalogi          */

/* Jeg har anvendt qsort som min foretrukne sorteringsalgoritme i denne aflevering. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH           6
#define MAX_CURRENT_STRING_LENGTH  60 
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
    char team_name[4];
    int  points;
    int  goals_scored_by_team;
    int  goals_scored_vs_team;
    int  goal_difference;
} team_struct;

enum team_name {AaB_index = 0, ACH_index, AGF_index, BIF_index, EFB_index, FCK_index, FCM_index,
                FCN_index, HOB_index, OB_index, RFC_index, SDR_index, VB_index, VEN_index};

void read_data(match_struct match_array[]);
void fill_in_team_array(team_struct team_array[], match_struct match_array[]);
void fill_in_team(team_struct team_array[], match_struct current_match, int is_home, char *team_name);
void update_team_score(team_struct team_array[], match_struct current_match, int is_home, int team_index);
int  match_result(int team_a_goals, int team_b_goals);
void fill_in_team_name(team_struct team_array[], char *team_name, int team_index);
int  element_compare_teams(const void *team_a, const void *team_b);
void print_table(team_struct team_array[]);

int main(void)
{   
    match_struct *match_array = calloc(sizeof(match_struct), TOTAL_MATCHES);
    team_struct *team_array = calloc(sizeof(team_struct), TOTAL_TEAMS);

    read_data(match_array);
    fill_in_team_array(team_array, match_array);
    qsort(team_array, 14, sizeof(team_struct), element_compare_teams);
    print_table(team_array);

    free(match_array);
    free(team_array);

    return (0);
}

/*Denne funktion læser filen "kampe2018-2019.txt" én linje af gangen. */
void read_data(match_struct match_array[])
{
    int i = 0;
    FILE *filepointer = fopen("kampe2018-2019.txt", "r");
    char current_string[MAX_CURRENT_STRING_LENGTH];

    if (filepointer != NULL)
    {      
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
            ++i;
        }
    } else {
        printf("Something went wrong. Your desired file was not found. Please try again.\n");
    }
    fclose(filepointer);
}

/* Denne funktion fortæller min fill_in_team hvilket hold, den skal håndtere, */
/* og om det er et home team eller et away team.                              */
void fill_in_team_array(team_struct team_array[], match_struct match_array[])
{
    int i = 0;

    for (i = 0; i < TOTAL_MATCHES; ++i)
    {
        /* Håndterer home team */
        fill_in_team(team_array, match_array[i], HOME, match_array[i].home_team);

        /* Håndterer away team */
        fill_in_team(team_array, match_array[i], AWAY, match_array[i].away_team);
    }
}

/* Denne funktion fylder mit team array ud ved at kalde de to funktioner update_team_score */
/* og fill_in_team_name. */
void fill_in_team(team_struct team_array[], match_struct current_match, int is_home, char *team_name)
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

/* Denne funktion opdaterer holdets score for faktorerne point, mål scoret af hold, */
/* mål scoret mod hold og målforskel.                                               */
void update_team_score(team_struct team_array[], match_struct current_match, int is_home, int team_index)
{
    if (is_home == 1)
    {
        team_array[team_index].points               += match_result(current_match.home_team_score, current_match.away_team_score);
        team_array[team_index].goals_scored_by_team += current_match.home_team_score;
        team_array[team_index].goals_scored_vs_team += current_match.away_team_score;
        team_array[team_index].goal_difference      += (current_match.home_team_score - current_match.away_team_score);

    } else if (is_home == 0) {
        team_array[team_index].points               += match_result(current_match.away_team_score, current_match.home_team_score);
        team_array[team_index].goals_scored_by_team += current_match.away_team_score;
        team_array[team_index].goals_scored_vs_team += current_match.home_team_score;
        team_array[team_index].goal_difference      += (current_match.away_team_score - current_match.home_team_score);   
    }
}

/* Denne funktion beregner, hvor mange point et hold skal have for en spillet kamp. */
int match_result(int team_a_goals, int team_b_goals)
{
    int result = 0;

    if (team_a_goals > team_b_goals)
    {
        result = 3;

    } else if (team_a_goals == team_b_goals) {
        result = 1;

    } else {
        result = 0;
    }
    return result;
}

/* Denne funktion fylder holdnavnet på holdet i den pågældende string ind i mit team_array, */
/* hvis den finder en tom string.                                                           */
void fill_in_team_name(team_struct team_array[], char *team_name, int team_index)
{
    if (strcmp(team_array[team_index].team_name, team_name) != 0)
    {
        strcpy(team_array[team_index].team_name, team_name);
    }
}

/* Denne funktion finder holdets position i Ligaen ved at se på faktorerne */
/* point, målforskel, mål scoret af holdet og mål scoret mod holdet.       */
int element_compare_teams(const void *team_a, const void *team_b)
{
    int result = 0;

    team_struct *team_array_a = (team_struct *)team_a;
    team_struct *team_array_b = (team_struct *)team_b;

    if (team_array_a->points == team_array_b->points)
    {
        result = (team_array_a->goal_difference - team_array_b->goal_difference);

        if (team_array_a->goal_difference == team_array_b->goal_difference)
        {
            result = (team_array_a->goals_scored_by_team - team_array_b->goals_scored_by_team);
            
            if (team_array_a->goals_scored_by_team == team_array_b->goals_scored_by_team)
            {
                result = (team_array_a->goals_scored_vs_team - team_array_b->goals_scored_vs_team);
            }
        }
    } else {
        result = (team_array_a->points - team_array_b->points);
    }
    return -result;
}

/* Denne funktion printer min tabel. */
void print_table(team_struct team_array[])
{
    int i = 0;

    printf("-------------------------------------------------------------------\n");
    printf("| Position |   Team   |  Points  | Goals by | Goals vs | Goal dif |\n");
    printf("-------------------------------------------------------------------\n");

    for (i = 0; i < TOTAL_TEAMS; ++i)
    {
        printf("| %8d | %8s | %8d | %8d | %8d | %8d |\n",
                (i + 1),
                team_array[i].team_name,
                team_array[i].points,
                team_array[i].goals_scored_by_team,
                team_array[i].goals_scored_vs_team,
                team_array[i].goal_difference );
    }
    printf("-------------------------------------------------------------------\n");
}