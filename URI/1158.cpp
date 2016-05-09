#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
        int n, x, y, sum;
        scanf("%d", &n);
        while(n--)
        {
                scanf("%d %d", &x, &y);
                if(x % 2 == 0)
                        ++x;
                sum = x;
                for(int i = 1; i < y; ++i)
                {
                    x += 2;
                    sum += x;
                }
                printf("%d\n", sum);
        }
        return 0;
}
