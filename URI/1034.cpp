#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX_BLOCKS 30
#define MAX_VALUE 1000010
using namespace std;

int minNumBlocks[MAX_VALUE];
int blockLengths[MAX_BLOCKS];

int compare(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}


void minNum(int numberOfBlocks, int desiredLength)
{
    int i, j, minimum;
    int greatestBlock = blockLengths[numberOfBlocks - 1];
    int prune = greatestBlock * greatestBlock;
    for(i = 0; i <= desiredLength; ++i)
        minNumBlocks[i] = 0;
    for(j = 1; j <= desiredLength; ++j)
    {
        minimum = -1;
        for(i = 0; i < numberOfBlocks; ++i)
            if(j - blockLengths[i] >= 0)
                if(minimum > minNumBlocks[j - blockLengths[i]] + 1 || minimum == -1)
                    minimum = minNumBlocks[j - blockLengths[i]] + 1;

        minNumBlocks[j] = minimum;

        //if(j > prune && (desiredLength - minNumBlocks[j]) % greatestBlock == 0)
        if(j > prune && (desiredLength - j) % greatestBlock == 0)
        {
//            std::cout << "minNumBlocks[" << j << "] = " << minNumBlocks[j] << std::endl;
//            std::cout << "Prune = " << prune << std::endl;
//            std::cout << "Number = " << (desiredLength - j) / greatestBlock << std::endl;
            minNumBlocks[desiredLength] = minNumBlocks[j] + ((desiredLength - j) / greatestBlock);
            break;
        }

    }
}

int main()
{
    int t, n, m, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        memset(blockLengths, 0, sizeof(blockLengths));
        for(i = 0; i < n; ++i)
            scanf("%d", &blockLengths[i]);
        qsort(blockLengths, n, sizeof(int), compare);
        minNum(n, m);
        printf("%d\n", minNumBlocks[m]);
    }

    return 0;
}