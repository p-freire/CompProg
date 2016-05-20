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

        for(int i = MAX - 1; i >= 0; --i)
            for(int j = MAX - i; j < MAX; ++j)
                result += mat[i][j];

        if(operation == 'M')
                result /= 66.0;

        printf("%.1lf\n", result);
        return 0;
}
