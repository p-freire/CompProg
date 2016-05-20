#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define SIZE 30

using namespace std;

int startGrid[SIZE];
int finishGrid[SIZE];

int findRacerIndex(int key)
{
    int i = 1;
    while(startGrid[i] != key)
        ++i;
    return i;
}

void moveForward(int startIndex, int finishIndex)
{
    while(startIndex > finishIndex)
    {
        swap(startGrid[startIndex], startGrid[startIndex - 1]);
        startIndex--;
    }
}

int main()
{
    int n, numOfPassings; // number of racers, number of passings
    int racerIndex; // just an aux variable

    while(scanf("%d", &n) != EOF)
    {
        memset(startGrid, 0, sizeof(startGrid));
        memset(finishGrid, 0, sizeof(finishGrid));
        numOfPassings = 0;

        for(int i = 1; i <= n; ++i)
            scanf("%d", &startGrid[i]);

        for(int i = 1; i <= n; ++i)
            scanf("%d", &finishGrid[i]);

        for(int i = 1; i <= n; ++i)
        {
            if(finishGrid[i] != startGrid[i]);
            {
                racerIndex = findRacerIndex(finishGrid[i]); // finds where the racer is in the start grid
                moveForward(racerIndex, i); // moves the racer to his/her right position
                numOfPassings += racerIndex - i;
            }
        }
        printf("%d\n", numOfPassings);
    }
    return 0;
}
