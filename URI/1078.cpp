#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 10; ++i)
        printf("%d x %d = %d\n", i, n, i * n);
    return 0;
}
