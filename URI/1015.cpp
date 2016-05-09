#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    double distance;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    distance = sqrt( (double)((x2 - x1)*(x2 - x1)) + (double)((y2 - y1)*(y2 - y1)) );
    printf("%.4lf\n", distance);
    return 0;
}