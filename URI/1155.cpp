#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    double result = 1.0;
    for(int i = 2; i <= 100; ++i)
        result += (double)(1.0/i);
    printf("%.2lf\n", result);
    return 0;
}
