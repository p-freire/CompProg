#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 10

int X[MAX];

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    X[0] = n;
    printf("N[0] = %d\n", n);
    for(int i = 1; i < MAX; ++i)
    {
        X[i] = X[i - 1] << 1;
        printf("N[%d] = %d\n", i, X[i]);

    }
    return 0;
}
