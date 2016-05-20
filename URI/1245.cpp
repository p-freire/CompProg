#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MAX 70

using namespace std;
int leftSide[MAX];
int rightSide[MAX];

int main()
{
    int m, n, nPairs; // boot size, number of boots, number of boot pairs
    char l; // boot foot

    while(scanf("%d", &n) != EOF)
    {
        memset(leftSide, 0, sizeof(leftSide));
        memset(rightSide, 0, sizeof(rightSide));
        nPairs = 0;

        while(n--)
        {
            scanf("%d %c", &m, &l);
            if(l == 'D')
            {
                if(leftSide[m])
                {
                    leftSide[m]--;
                    nPairs++;
                }
                else
                    rightSide[m]++;
            }
            else
            {
                if(rightSide[m])
                {
                    rightSide[m]--;
                    nPairs++;
                }
                else
                    leftSide[m]++;
            }
        }
        printf("%d\n", nPairs);
    }
    return 0;
}
