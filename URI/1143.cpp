#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    long int n;
    scanf("%ld", &n);
    for(int i = 1; i <= n ; ++i)
        printf("%ld %ld %ld\n", i, i * i, i * i * i);
    return 0;
}
