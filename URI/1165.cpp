#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 1000010

using namespace std;
long long int primes[MAX];

void calc_primes()
{
    long long int j;
    primes[0] = 0;
    primes[1] = 0;
    for(long int i = 2; i < MAX; ++i)
        primes[i] = i;
    for(int i = 2; i < MAX; ++i)
    {
        if(primes[i] != 0)
        {
            j = i << 1;
            for( ; j < MAX; j += i)
                primes[j] = 0;
        }
    }
}

int main()
{
    int n;
    long long int num;
    calc_primes();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lld", &num);
        if(primes[num] != 0)
            printf("%lld eh primo\n", num);
        else
            printf("%lld nao eh primo\n", num);
    }
    return 0;
}
