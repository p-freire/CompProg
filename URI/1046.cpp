#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int a, b, total;
    scanf("%d %d", &a, &b);
    total = (b - a) > 0 ? b - a : (24 - a) + b;
    printf("O JOGO DUROU %d HORA(S)\n", total);
    return 0;
}
