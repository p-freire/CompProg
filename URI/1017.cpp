#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int hours, speed;
    double gas_needed;
    scanf("%d %d", &hours, &speed);
    gas_needed = (hours * speed) / 12.0;
    printf("%.3lf\n", gas_needed);
    return 0;
}