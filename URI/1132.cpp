#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int main()
{
    int a, b, min_num, max_num, sum;
    sum = 0;
    scanf("%d %d", &a, &b);
    min_num = MIN(a,b);
    max_num = MAX(a,b);
    for(int i = min_num; i <= max_num; ++i)
        sum += (i % 13 != 0) ? i : 0;
    printf("%d\n", sum);
    return 0;
}
