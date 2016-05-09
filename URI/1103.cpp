#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int h1, m1, h2, m2;
    int num_min;
    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2))
    {
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break;
        num_min = 0;

        if(m2 >= m1)
            num_min += (m2 - m1);
        else
        {
            num_min += (60 - (m1 - m2));
            h1 = h1 + 1 > 23 ? 0 : ++h1;
        }

        if(h2 >= h1)
            num_min += (h2 - h1) * 60;
        else
            num_min += (24 - (h1 - h2)) * 60;
        printf("%d\n", num_min);
    }
    return 0;
}