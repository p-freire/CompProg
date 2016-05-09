#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int x, z, sum, num_of_integers;;
    while(scanf("%d %d", &x, &z) != EOF)
    {
        num_of_integers = 1;
        while(z <= x)
            scanf("%d", &z);
        sum = x;
        while(sum < z)
        {
            sum += ++x;
            ++num_of_integers;
        }
        printf("%d\n", num_of_integers);
    }
    return 0;
}
