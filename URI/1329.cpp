#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int n, maryWon, johnWon; // number of games, number of times Maria won, number of times Joao won
    int aux;
    maryWon = 0; johnWon = 0;

    scanf("%d", &n);
    while(n != 0)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &aux);
            aux == 0 ? ++maryWon : ++johnWon;
        }
        printf("Mary won %d times and John won %d times\n", maryWon, johnWon);
        maryWon = 0; johnWon = 0;
        scanf("%d", &n);
    }
    return 0;
}