#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int main()
{
    double a, b, c, hyp_side;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a == MAX(a, b) && a == MAX(a, c) && a < b + c
       || b == MAX(b, a) && b == MAX(b, c) && b < a + c
       || c == MAX(c, a) && c == MAX(c, b) && c < a + b)
        printf("Perimetro = %.1f\n", a + b + c);
    else
        printf("Area = %.1lf\n", (a + b) * c / 2.0);


    return 0;
}
