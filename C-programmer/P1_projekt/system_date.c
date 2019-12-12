#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
    int day;
    int month;
    int year;
} time_of_day;

void get_current_time(time_of_day *current_time);

int main(void)
{
    time_of_day current_time;

    /* Funktionen get_current_time kaldes, hvilket danner en struct med current
       time data. */
    get_current_time(&current_time);

    printf("%d/%d/%d\n", current_time.day, current_time.month,
                         current_time.year);

   return 0;
}

void get_current_time(time_of_day *current_time)
{
  time_t now;
  struct tm *now_tm;

  now = time(NULL);
  now_tm = localtime(&now);
  current_time->day    = now_tm->tm_mday;
  current_time->month  = now_tm->tm_mon  + 1;
  current_time->year   = now_tm->tm_year + 1900;
}