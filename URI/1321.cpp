#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FOR_E(i, a, b) for(int i = (a); i <= (b); ++i)

int princess[3], prince[2], tmp_hand[3];
bool cards[53];

int compare(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    int card;
    while(scanf("%d %d %d %d %d", &princess[0], &princess[1], &princess[2], &prince[0], &prince[1]) && princess[0] != 0)
    {
        memset(cards, 0, sizeof(cards));
        cards[princess[0]] = true; cards[princess[1]] = true; cards[princess[2]] = true; cards[prince[0]] = true; cards[prince[1]] = true;
        qsort(princess, 3, sizeof(int), compare);
        qsort(prince, 2, sizeof(int), compare);

        card = -1;
        FOR(i, 1, 53)
        {
            if(!cards[i])
            {
                tmp_hand[0] = prince[0];
                tmp_hand[1] = prince[1];
                tmp_hand[2] = i;
                qsort(tmp_hand, 3, sizeof(int), compare);
                card = (tmp_hand[0] > princess[1] || tmp_hand[1] > princess[2]) ? i : -1;
                if(card != -1)
                    break;
            }
        }
        printf("%d\n", card);
    }
    return 0;
}
