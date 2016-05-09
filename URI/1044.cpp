#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int main()
{
    int a, b, min_num;
    scanf("%d %d", &a, &b);
    min_num = MIN(a, b);
    if(a % min_num == 0 && b % min_num == 0)
        printf("Sao Multiplos\n");
    else
        printf("Nao sao Multiplos\n");

    return 0;
}
