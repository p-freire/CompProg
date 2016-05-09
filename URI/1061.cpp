#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define BUFFER 1024

using namespace std;

int main()
{
    char buff[BUFFER];
    int ini_day, ini_hour, ini_min, ini_sec, final_day, final_hour, final_min, final_sec;
    int total_days, total_hours, total_mins, total_secs;
    total_days = total_hours = total_mins = total_secs = 0;

    scanf("%s", buff);
    scanf("%d", &ini_day);
    scanf("%d", &ini_hour);
    scanf("%s", buff);
    scanf("%d", &ini_min);
    scanf("%s", buff);
    scanf("%d", &ini_sec);

    scanf("%s", buff);
    scanf("%d", &final_day);
    scanf("%d", &final_hour);
    scanf("%s", buff);
    scanf("%d", &final_min);
    scanf("%s", buff);
    scanf("%d", &final_sec);

    total_secs = (final_sec > ini_sec) ? 60 + (final_sec - ini_sec) : (60 - ini_sec) + final_sec;
    if(total_secs >= 60)
    {
        ++total_mins;
        ++ini_min;
        total_secs = total_secs % 60;
    }
    total_mins += (final_min > ini_min) ? 60 + (final_min - ini_min) : (60 - ini_min) + final_min;
    if(total_mins >= 60)
    {
        ++total_hours;
        ++ini_hour;
        total_mins = total_mins % 60;
    }
    total_hours += (final_hour > ini_hour) ? 24 + (final_hour - ini_hour) : (24 - ini_hour) + final_hour;
    if(total_hours >= 24)
    {
        ++total_days;
        ++ini_day;
        total_hours = total_hours % 24;
        total_days += final_day - ini_day;
    }
    else
        total_days += final_day - ini_day - 1;


    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", total_days, total_hours, total_mins, total_secs);

    return 0;
}
