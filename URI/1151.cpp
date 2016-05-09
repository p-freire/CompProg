#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 50
using namespace std;
int fibonacci[MAX];

void calc_fibonacci()
{
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int i = 2; i < MAX; ++i)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
}

int main()
{
    int n;
    scanf("%d", &n);
    calc_fibonacci();
    for(int i = 0; i < n; ++i)
        if(i == n - 1)
            printf("%d\n", fibonacci[i]);
        else
            printf("%d ", fibonacci[i]);
    return 0;
}
