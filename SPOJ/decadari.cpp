#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int sistema24[4];
char entrada[8];
 
using namespace std;
 
int main()
{
    int somaCentTotal;
    for(int i = 0; i < 4; i++)
    {
        sistema24[i] = 0;
        entrada[i] = 0;
        entrada[i+1] = 0;
    }
 
    while(scanf("%s", entrada) != EOF)
    {
        sistema24[0] = 10*((int)entrada[0] - 48) + ((int)entrada[1] - 48);
        sistema24[1] = 10*((int)entrada[2] - 48) + ((int)entrada[3] - 48);
        sistema24[2] = 10*((int)entrada[4] - 48) + ((int)entrada[5] - 48);
        sistema24[3] = 10*((int)entrada[6] - 48) + ((int)entrada[7] - 48);
 
        somaCentTotal = (sistema24[0] * 3600 + sistema24[1] * 60 + sistema24[2]) * 100 + sistema24[3];
 
        if(somaCentTotal > 0)
        {
            somaCentTotal = somaCentTotal * 125;
            somaCentTotal = somaCentTotal/108;
            printf("%07d\n", somaCentTotal);
        }
        else
        {
            printf("0000000\n");
        }
    }
    return 0;
}