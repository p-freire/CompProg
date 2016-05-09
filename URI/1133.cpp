#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

int main()
{
    int a, b, min_num, max_num;
    scanf("%d %d", &a, &b);
    min_num = MIN(a,b);
    max_num = MAX(a,b);
    for(int i = min_num + 1; i < max_num; ++i)
        if(i % 5 == 2 || i % 5 == 3)
            printf("%d\n", i);
    return 0;
}
