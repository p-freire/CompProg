#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define NUM_BILLS 7
using namespace std;

int main()
{
    int num_bills[NUM_BILLS];
    int bills[] = {100, 50, 20, 10, 5, 2, 1};
    int number, tmp;
    scanf("%d", &number);
    tmp = number;
    for(int i = 0; i < NUM_BILLS; ++i)
    {
        num_bills[i] = tmp / bills[i];
        tmp = tmp % bills[i];
    }
    printf("%d\n", number);
    for(int i = 0; i < NUM_BILLS; ++i)
        printf("%d nota(s) de R$ %d,00\n", num_bills[i], bills[i]);
    return 0;
}