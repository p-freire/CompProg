#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    double distance;
    int minutes;
    scanf("%lf", &distance);
    minutes = (distance/30) * 60;
    printf("%d minutos\n", minutes);
    return 0;
}