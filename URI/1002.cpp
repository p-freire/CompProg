#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define PI 3.14159
using namespace std;

int main()
{
    double radius;
    scanf("%lf", &radius);
    printf("A=%.4lf\n", radius * radius * PI);
    return 0;
}
