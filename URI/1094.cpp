#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int num_rabbits, num_mice, num_frogs;
    int n, aux, total;
    char c;
    num_rabbits = num_mice = num_frogs = 0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %c", &aux, &c);
        if(c == 'R')
            num_mice += aux;
        else if(c == 'C')
            num_rabbits += aux;
        else
            num_frogs += aux;
    }
    total = num_mice + num_rabbits + num_frogs;
    printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\n", total, num_rabbits, num_mice, num_frogs);
    printf("Percentual de coelhos: %.2lf %%\n", (double)num_rabbits/(double)total * 100.00);
    printf("Percentual de ratos: %.2lf %%\n", (double)num_mice/(double)total * 100.00);
    printf("Percentual de sapos: %.2lf %%\n", (double)num_frogs/(double)total * 100.00);
    return 0;
}
