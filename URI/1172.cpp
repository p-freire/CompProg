#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 10

int X[MAX];

using namespace std;

int main()
{
    for(int i = 0; i < MAX; ++i)
    {
        scanf("%d", &X[i]);
        if(X[i] <= 0)
            X[i] = 1;
        printf("X[%d] = %d\n", i, X[i]);

    }
    return 0;
}
