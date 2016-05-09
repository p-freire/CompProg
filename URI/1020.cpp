#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int value, num_days, num_months, num_years;
    scanf("%d", &value);
    num_years = value / 365;
    value = value % 365;
    num_months = value / 30;
    value = value % 30;
    num_days = value;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", num_years, num_months, num_days);

    return 0;
}
