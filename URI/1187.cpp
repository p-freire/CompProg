#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 12
using namespace std;

double mat[MAX][MAX];

int main()
{
        char operation;
        double result = 0.0;
        scanf("%c", &operation);
        for(int i = 0; i < MAX; ++i)
                for(int j = 0; j < MAX; ++j)
                        scanf("%lf", &mat[i][j]);
        int upper, lower;
        upper = 10;
        lower = 1;
        for(int i = 0; i < 5; ++i)
        {
                for(int j = lower; j <= upper; ++j)
                {
                        result += mat[i][j];
                }
                --upper;
                ++lower;
        }
        if(operation == 'M')
                result /= 30.0;
        printf("%.1lf\n", result);
        return 0;
}
