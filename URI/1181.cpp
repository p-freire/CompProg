#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 12
using namespace std;

double mat[MAX][MAX];

int main()
{
        int line;
        char operation;
        double result = 0.0;
        scanf("%d %c", &line, &operation);
        for(int i = 0; i < MAX; ++i)
                for(int j = 0; j < MAX; ++j)
                        scanf("%lf", &mat[i][j]);
        for(int i = 0; i < MAX; ++i)
                result += mat[line][i];
        if(operation == 'M')
                result /= 12.0;
        printf("%.1lf\n", result);
        return 0;
}
