#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 65
using namespace std;

unsigned long long int fibonacci[MAX];

void calc_fibonacci()
{
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int i = 2; i < MAX; ++i)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
}

int main()
{
    calc_fibonacci();
    int n, a;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &a);
        printf("Fib(%d) = %lld\n", a, fibonacci[a]);
    }
    return 0;
}
