#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
        int n, sum;
        while(scanf("%d", &n) && n != 0)
        {
                sum = 0;
                if(abs(n) % 2 == 1)
                        ++n;
                sum += n;
                for(int i = 0; i < 4; ++i)
                {
                        n += 2;
                        sum += n;
                }
                printf("%d\n", sum);
        }
        return 0;
}
