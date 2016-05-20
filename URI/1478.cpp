#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MAX 100

int mat[MAX][MAX];

using namespace std;

void set_matrix(int dim)
{
    int num;
    bool sum;
    for(int i = 0; i < dim; ++i)
        mat[i][0] = i + 1;
    for(int j = 0; j < dim; ++j)
        mat[0][j] = j + 1;
    for(int i = 1; i < dim; ++i)
    {
        sum = false;
        for(int j = 1; j < dim; ++j)
        {
            if(mat[i][j - 1] == 1)
                sum = true;
            else if(mat[i][j - 1] == dim)
                sum = false;
            if(sum)
                mat[i][j] = mat[i][j - 1] + 1;
            else
                mat[i][j] = mat[i][j - 1] - 1;

        }
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
        set_matrix(dim);
        print(dim);
    }
    return 0;
}
