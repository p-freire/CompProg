#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 100

using namespace std;

int main()
{
    double a;
    scanf("%lf", &a);
    for(int i = 0; i < MAX; ++i)
    {
        printf("N[%d] = %.4lf\n", i, a);
        a /= 2.0;
    }
    return 0;
}
