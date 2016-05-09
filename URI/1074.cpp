#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, value;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &value);
        if(value == 0)
            printf("NULL\n");
        else
        {
            if(abs(value) % 2 == 0)
                printf("EVEN ");
            else
                printf("ODD ");
            if(value < 0)
                printf("NEGATIVE\n");
            else
                printf("POSITIVE\n");
        }
    }
    return 0;
}
