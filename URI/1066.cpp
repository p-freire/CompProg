#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 5
using namespace std;

int main()
{
    int even_nums, odd_nums, pos_nums, neg_nums, number;
    even_nums = odd_nums = pos_nums = neg_nums = 0;
    for(int i = 0; i < MAX; ++i)
    {
        scanf("%d", &number);
        if(number % 2 == 0)
            ++even_nums;
        else
            ++odd_nums;
        if(number > 0)
            ++pos_nums;
        else if(number < 0)
            ++neg_nums;
    }
    printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n%d valor(es) positivo(s)\n%d valor(es) negativo(s)\n", even_nums, odd_nums, pos_nums, neg_nums);
    return 0;
}
