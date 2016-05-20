#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 20

using namespace std;

int N[MAX];

int main()
{
    for(int i = 0; i < MAX; ++i)
        scanf("%d", &N[i]);
    int j = MAX - 1;
    for(int i = 0; i < 10; ++i)
    {
        swap(N[i], N[j]);
        --j;
    }
    for(int i = 0; i < MAX; ++i)
        printf("N[%d] = %d\n", i, N[i]);

    return 0;
}
