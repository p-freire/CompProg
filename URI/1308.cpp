#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
unsigned long long int numberOfLevels(unsigned long long int numOfSoldiers)
{
    return(unsigned long long int)(-1 + (unsigned long long int)sqrt(1 + 4 * (numOfSoldiers * 2)))/2;
    //return numOfSoldiers << 2;
}

int main()
{
    unsigned long long int n, soldiers; // number of test cases, number of soldiers
    scanf("%lld", &n);
    while(n--)
    {
        scanf("%lld", &soldiers);
        printf("%lld\n", numberOfLevels(soldiers));
    }
    return 0;
}
