#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    long int n, n2, n3;
    scanf("%ld", &n);
    for(int i = 1; i <= n; ++i)
    {
        n2 = i * i;
        n3 = i * i * i;
        printf("%ld %ld %ld\n", i, n2, n3);
        printf("%ld %ld %ld\n", i, n2 + 1, n3 + 1);
    }
    return 0;
}
