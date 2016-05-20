#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c; // numbers for Alice, Beto and Clara


    while(scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        printf("%c\n", (a + b + c) % 3 == 0? '*' : 'A' + (a == c) + 2*(a == b));
    }

    return 0;
}