#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MAX 10010
using namespace std;

int diversArray[MAX];

int main()
{
    int n, r; // number of volunteers that went, number of volunteers that came back
    int aux;
    bool everyoneReturned = true;
    memset(diversArray, 0, sizeof(diversArray));

    while(scanf("%d %d", &n, &r) != EOF)
    {
        while(r--)
        {
            scanf("%d", &aux);
            diversArray[aux] = 1;
        }

        for(int i = 1; i <= n; i++)
            if(!diversArray[i])
            {
                everyoneReturned = false;
                printf("%d ", i);
            }

        if(everyoneReturned)
            printf("*");

        printf("\n");
        everyoneReturned = true;
        memset(diversArray, 0, sizeof(diversArray));
    }
    return 0;
}