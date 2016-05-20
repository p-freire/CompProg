#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MAX 5
#define IT 15
using namespace std;

int even_nums[MAX];
int odd_nums[MAX];

void print_even(int arr_size)
{
        for(int i = 0; i < arr_size; ++i)
                printf("par[%d] = %d\n", i, even_nums[i]);
}

void print_odd(int arr_size)
{
        for(int i = 0; i < arr_size; ++i)
                printf("impar[%d] = %d\n", i, odd_nums[i]);
}

int main()
{
        int num, evens, odds;
        evens = odds = 0;
        for(int i = 0; i < IT; ++i)
        {
                scanf("%d", &num);
                if(abs(num) % 2 == 0)
                {
                        if(evens == MAX)
                        {
                                print_even(MAX);
                                evens = 0;
                        }
                        even_nums[evens] = num;
                        ++evens;
                }
                else
                {
                        if(odds == MAX)
                        {
                                print_odd(MAX);
                                odds = 0;
                        }
                        odd_nums[odds] = num;
                        ++odds;
                }
        }
        print_odd(odds);
        print_even(evens);
        return 0;
}
