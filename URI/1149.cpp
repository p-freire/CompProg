#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int a, n, sum;
    while(scanf("%d %d", &a, &n) != EOF)
    {
        sum = 0;
        while(n <= 0)
            scanf("%d", &n);
        for(int i = a; i < a + n; ++i)
            sum += i;
        printf("%d\n", sum);
    }
    return 0;
}
