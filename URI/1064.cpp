#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 6

using namespace std;

int main()
{
    double number, mean;
    int positive_nums;
    mean = 0.0;
    positive_nums = 0;
    for(int i = 0; i < MAX; ++i)
        if(scanf("%lf", &number) && number > 0.0)
        {
            ++positive_nums;
            mean += number;
        }
    mean = mean/(double)positive_nums;
    printf("%d valores positivos\n%.1lf\n", positive_nums, mean);
    return 0;
}
