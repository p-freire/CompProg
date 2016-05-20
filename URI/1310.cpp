#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAX 60
#define MIN_INT -999999

int profits[MAX];

int maxSum(int n)
{
    int tempMax, maxSum;
    tempMax = 0;
    maxSum = MIN_INT;
    for(int i = 0; i < n; ++i)
    {
        tempMax += profits[i];
        if(tempMax > maxSum)
            maxSum = tempMax;
        if(tempMax < 0)
            tempMax = 0;
    }
    return maxSum;
}

void setProfits(int n, int cost)
{
    for(int i = 0; i < n; ++i)
        profits[i] = profits[i] - cost;
}


int main()
{
    int n, cost; // number of days, cost per day
    int value;
    while(scanf("%d %d", &n, &cost) != EOF)
    {
        memset(profits, 0, sizeof(profits));
        for(int i = 0; i < n; ++i)
            scanf("%d", &profits[i]);
        setProfits(n, cost);
        value = maxSum(n);
        if(value > 0)
            printf("%d\n", value);
        else
            printf("0\n");
    }
    return 0;
}
