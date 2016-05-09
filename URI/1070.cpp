#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 6
using namespace std;

int main()
{
    int value;
    scanf("%d", &value);
    if(value % 2 == 0);
        ++value;
    for(int i = 0; i < MAX; ++i)
    {
        printf("%d\n", value);
        value += 2;
    }
    return 0;
}
