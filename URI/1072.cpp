#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int n, x, in, out;
    in = out = 0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        if(x >= 10 && x <= 20)
            ++in;
        else
            ++out;
    }
    printf("%d in\n%d out\n", in, out);
    return 0;
}
