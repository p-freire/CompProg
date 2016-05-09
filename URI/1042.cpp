#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MAX_NUMBERS 3

using namespace std;

int main()
{
    int numbers[MAX_NUMBERS];
    int sorted_numbers[MAX_NUMBERS];
    for(int i = 0; i < MAX_NUMBERS; ++i){
        scanf("%d", &numbers[i]);
        sorted_numbers[i] = numbers[i];
    }

    for(int i = 0; i < MAX_NUMBERS; ++i)
        for(int j = i + 1; j < MAX_NUMBERS; ++j)
            if(sorted_numbers[i] > sorted_numbers[j])
                swap(sorted_numbers[i], sorted_numbers[j]);

    for(int i = 0; i < MAX_NUMBERS; ++i)
        printf("%d\n", sorted_numbers[i]);
    printf("\n");
    for(int i = 0; i < MAX_NUMBERS; ++i)
        printf("%d\n", numbers[i]);
    return 0;
}
