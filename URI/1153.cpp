#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int fatorial(int n)
{
    if(n == 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fatorial(n));
    return 0;
}
