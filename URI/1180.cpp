#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
        int n, smallest, position, tmp;
        scanf("%d", &n);
        position = 0;
        scanf("%d", &smallest);
        for(int i = 1; i < n; ++i)
        {
                scanf("%d", &tmp);
                if(tmp < smallest)
                {
                        smallest = tmp;
                        position = i;
                }
        }
        printf("Menor valor: %d\nPosicao: %d\n", smallest, position);
        return 0;
}
