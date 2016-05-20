#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define MAX 15

int attack[MAX];
int defense[MAX];

int compare(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

bool isOffside(int n)
{
    int aux, i;
    aux = defense[0];
    i = 1;
    while(defense[i] == aux && i + 1 < n) ++i; // gets the second smallest value index in defense array
    if(attack[0] >= defense[i] || (attack[0] >= defense[0] && attack[0] >= defense[1]))
        return false;
    else
        return true;
}

int main()
{
    int a, d;
    while(scanf("%d %d", &a, &d) && a != 0)
    {
        memset(attack, 0, sizeof(attack));
        memset(defense, 0, sizeof(defense));

        for(int i = 0; i < a; ++i)
            scanf("%d", &attack[i]);
        for(int i = 0; i < d; ++i)
            scanf("%d", &defense[i]);

        qsort(attack, a, sizeof(int), compare);
        qsort(defense, d, sizeof(int), compare);
        printf(isOffside(d) ? "Y\n" : "N\n");
    }
    return 0;
}
