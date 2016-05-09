#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int greatest = -1;
    int num, pos;
    for(int i = 0; i < 100; ++i)
    {
        scanf("%d", &num);
        if(num > greatest)
        {
            greatest = num;
            pos = i + 1;
        }
    }
    printf("%d\n%d\n", greatest, pos);

    return 0;
}
