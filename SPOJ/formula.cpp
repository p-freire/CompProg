#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAX_RUNNERS 110
#define MAX_SCORES 15
 
using namespace std;
 
int runnersPositions[MAX_RUNNERS][MAX_RUNNERS];
int scores[MAX_SCORES][MAX_RUNNERS];
int runnersPoints[MAX_RUNNERS];
int winners[MAX_RUNNERS];
int g, p, s; // number of grand prix, number of pilots, number of scores
 
int findRunner(int race, int position)
{
    int i = 1;
    while(runnersPositions[race][i] != position)
        ++i;
    return i;
}
 
void calculatePoints(int scoreIndex)
{
    int aux;
    for(int i = 1; i <= g; ++i)
        for(int j = 1; j <= scores[scoreIndex][0]; ++j)
        {
            aux = findRunner(i, j);
            runnersPoints[aux] += scores[scoreIndex][j];
        }
}
 
int findMaxValue()
{
    int maxValue = runnersPoints[1];
    for(int i = 2; i <= p; ++i)
        if(runnersPoints[i] > maxValue)
            maxValue = runnersPoints[i];
    return maxValue;
}
 
void printWinners()
{
    int maxPoints = findMaxValue();
    int j = 0;
    for(int i = 1; i <= p; ++i)
        if(runnersPoints[i] == maxPoints)
        {
            winners[j] = i;
            ++j;
        }
    printf("%d", winners[0]);
    for(int i = 1; i < j; ++i)
        printf(" %d", winners[i]);
    printf("\n");
}
 
int main()
{
    scanf("%d", &g);
    while(g)
    {
        memset(runnersPositions, 0, sizeof(runnersPositions));
        memset(scores, 0, sizeof(scores));
        memset(runnersPoints, 0, sizeof(runnersPoints));
 
        scanf("%d", &p);
 
        for(int i = 1; i <= g; ++i)
            for(int j = 1; j <= p; ++j)
                scanf("%d", &runnersPositions[i][j]);
 
        scanf("%d", &s);
        for(int i = 0; i < s; ++i)
        {
            scanf("%d", &scores[i][0]); // number of positions that get points
            for(int j = 1; j <= scores[i][0]; ++j)
                scanf("%d", &scores[i][j]);
        }
 
        for(int i = 0; i < s; ++i)
        {
            memset(winners, 0, sizeof(winners));
            calculatePoints(i);
            printWinners();
            memset(runnersPoints, 0, sizeof(runnersPoints));
        }
        scanf("%d", &g);
    }
    return 0;
}