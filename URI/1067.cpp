#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int value;
    scanf("%d", &value);
    if(value % 2 == 0)
        --value;
    for(int i = 1; i <= value; i += 2)
        printf("%d\n", i);
    return 0;
}
