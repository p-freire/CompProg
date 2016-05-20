#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 1000

int X[MAX];

using namespace std;

int main()
{
    int t, j;
    scanf("%d", &t);
    j = 0;
    for(int i = 0; i < MAX; ++i)
    {
        if(j == t)
            j = 0;
        X[i] = j;
        ++j;
        printf("N[%d] = %d\n", i, X[i]);

    }
    return 0;
}
