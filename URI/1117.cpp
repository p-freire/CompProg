#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    double grade1, grade2;
    while(scanf("%lf", &grade1) && (grade1 < 0.0 || grade1 > 10.0))
        printf("nota invalida\n");
    while(scanf("%lf", &grade2) && (grade2 < 0.0 || grade2 > 10.0))
        printf("nota invalida\n");
    printf("media = %.2lf\n", (double)((grade1 + grade2)/ 2.0));


    return 0;
}
