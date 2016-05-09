#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int josephus(int n, int k)
{
    if(n == 1)
        return 1;
    else
        return((josephus(n - 1, k) + k - 1) % n) + 1;
}

int main()
{
    int nc, n, k;
    int counter = 1;
    scanf("%d", &nc);
    while(nc--)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", counter, josephus(n, k));
        ++counter;
    }
    return 0;
}