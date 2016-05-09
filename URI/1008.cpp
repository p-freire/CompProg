#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int emp_number, num_hours;
    double value_per_hour;
    scanf("%d %d %lf", &emp_number, &num_hours, &value_per_hour);
    printf("NUMBER = %d\nSALARY = U$ %.2lf\n", emp_number, (double)num_hours * value_per_hour);
    return 0;
}
