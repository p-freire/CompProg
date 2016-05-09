#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX 100100

int numbers[MAX];
int numOfExchanges = 0;

bool isSorted(int n)
{
    for(int i = 1; i <= n; ++i)
        if(numbers[i] != i)
            return false;
    return true;
}

void bubble(int n)
{
    int aux;
    while(!isSorted(n))
    {
        //std::cout << "Here\n";
        for(int i = 1; i <= n; ++i)
            if(numbers[i] != i)
            {
                aux = numbers[i];
                std::swap(numbers[i], numbers[aux]);
                ++numOfExchanges;
                //std::cout << "Exchanges = " << numOfExchanges << "\n";
            }
    }
}

int main()
{
    int n; // number of elements in the array
    while(scanf("%d", &n) && n != 0)
    {
        numOfExchanges = 0;
        memset(numbers, 0, sizeof(numbers));
        for(int i = 1; i <= n; ++i)
            scanf("%d", &numbers[i]);
        bubble(n);
        printf(numOfExchanges % 2 == 0 ? "Carlos\n" : "Marcelo\n");
    }
    return 0;
}
