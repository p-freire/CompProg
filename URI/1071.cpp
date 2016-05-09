#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

int main()
{
    int a, b, sum, min_value, max_value;
    scanf("%d %d", &a, &b);
    min_value = MIN(a,b) + 1; max_value = MAX(a,b);
    sum = 0;
    for(int i = min_value; i < max_value; ++i)
        if(abs(i) % 2 == 1)
            sum += i;
    printf("%d\n", sum);
    return 0;
}
