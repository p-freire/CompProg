#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MAX 2010

using namespace std;

int arrayOfNumbers[MAX];

int main()
{
    int n; // number of instances
    int aux;
    memset(arrayOfNumbers, 0, sizeof(arrayOfNumbers));

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &aux);
        ++arrayOfNumbers[aux];
    }

    for(int i = 1; i <= MAX; ++i)
        if(arrayOfNumbers[i])
            printf("%d aparece %d vez(es)\n", i, arrayOfNumbers[i]);

    return 0;
}
