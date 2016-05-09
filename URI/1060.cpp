#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 6

using namespace std;

int main()
{
    double value;
    int positive_values;
    positive_values = 0;
    for(int i = 0; i < MAX; ++i)
    {
        scanf("%lf", &value);
        if(value > 0)
            ++positive_values;
    }
    printf("%d valores positivos\n", positive_values);
    return 0;
}
