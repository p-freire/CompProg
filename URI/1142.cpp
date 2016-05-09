#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int n, start;
    start = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = start; j <= start + 2; ++j)
            printf("%d ", j);
        printf("PUM\n");
        start += 4;
    }
    return 0;
}
