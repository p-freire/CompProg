#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int x, y;
    while(scanf("%d %d", &x, &y) && x != 0 && y != 0)
    {
        if(x > 0 && y > 0)
           printf("primeiro\n");
        else if(x > 0 && y < 0)
            printf("quarto\n");
        else if(x < 0 && y > 0)
            printf("segundo\n");
        else
            printf("terceiro\n");
    }
    return 0;
}
