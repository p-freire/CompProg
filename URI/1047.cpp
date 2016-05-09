#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int begin_hour, begin_minute, end_hour, end_minute, total_minutes, total_hours;
    scanf("%d %d %d %d", &begin_hour, &begin_minute, &end_hour, &end_minute);
    total_minutes = (60 - begin_minute) + end_minute;
    ++begin_hour;
    total_hours = (end_hour - begin_hour) > 0 ? end_hour - begin_hour : (24 - begin_hour) + end_hour;
    if(total_minutes > 59)
    {
        ++total_hours;
        total_minutes = total_minutes - 60;
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", total_hours, total_minutes);

    return 0;
}
