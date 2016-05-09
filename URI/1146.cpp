#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int x;
    while(scanf("%d", &x) && x != 0)
    {
        for(int i = 1; i <= x; ++i)
            if(i % x == 0)
                printf("%d\n", i);
            else
                printf("%d ", i);
    }
    return 0;
}
