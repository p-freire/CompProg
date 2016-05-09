#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    double a, b, c, mean;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lf %lf %lf", &a, &b, &c);
        mean = ((2 * a) + (3 * b) + (5 * c)) / 10.0;
        printf("%.1lf\n", mean);
    }
    return 0;
}
