#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void calc_mean()
{
    double grade1, grade2;
    while(scanf("%lf", &grade1) && (grade1 < 0.0 || grade1 > 10.0))
        printf("nota invalida\n");
    while(scanf("%lf", &grade2) && (grade2 < 0.0 || grade2 > 10.0))
        printf("nota invalida\n");
    printf("media = %.2lf\n", (double)((grade1 + grade2)/ 2.0));
}

int main()
{
    int option;
    calc_mean();
    do
    {
        printf("novo calculo (1-sim 2-nao)\n");
        scanf("%d", &option);
        if(option == 1)
            calc_mean();
    }while(option != 2);

    return 0;
}
