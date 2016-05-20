#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MAX 100

int mat[MAX][MAX];

using namespace std;

void set_matrix(int lower, int upper)
{
    int num = 1;
    while(upper - lower >= 0)
    {
        for(int i = lower; i <= upper; ++i)
            mat[lower][i] = num;
        for(int i = lower; i <= upper; ++i)
            mat[upper][i] = num;
        for(int j = lower; j <= upper; ++j)
            mat[j][lower] = num;
        for(int j = lower; j <= upper; ++j)
            mat[j][upper] = num;
        upper--;
        lower++;
        ++num;
    }
}

void print(int dim)
{
    for(int i = 0; i < dim; ++i)
    {
        printf("%3d", mat[i][0]);
        for(int j = 1; j < dim; ++j)
        {
            printf(" %3d", mat[i][j]);

        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    int dim;
    while(scanf("%d", &dim) && dim != 0)
    {
        set_matrix(0, dim - 1);
        print(dim);
    }
    return 0;
}
