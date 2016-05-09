#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    double mean;
    int age, n;
    mean = 0.0;
    n = 0;
    while(scanf("%d", &age) && age >= 0)
    {
        ++n;
        mean += (double)age;
    }
    printf("%.2lf\n", mean/(double)n);
    return 0;
}
