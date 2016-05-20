#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l, r; // left hand, right hand
    while(scanf("%d %d", &l, &r))
    {
        if(r == 0 && l == 0)
             break;
        printf("%d\n", l + r);
    }
    return 0;
}