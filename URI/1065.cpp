#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 5
using namespace std;

int main()
{
    int num, even_nums;
    even_nums = 0;
    for(int i = 0; i < MAX; ++i)
        if(scanf("%d", &num) && num % 2 == 0)
            ++even_nums;
    printf("%d valores pares\n", even_nums);
    return 0;
}
