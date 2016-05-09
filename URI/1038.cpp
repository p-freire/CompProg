#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int code, quantity;
    scanf("%d %d", &code, &quantity);
    printf("Total: R$ ");
    switch(code)
    {
    case 1:
        printf("%.2f\n", quantity * 4.0);
        break;
    case 2:
        printf("%.2f\n", quantity * 4.50);
        break;
    case 3:
        printf("%.2f\n", quantity * 5.0);
        break;
    case 4:
        printf("%.2f\n", quantity * 2.0);
        break;
    case 5:
        printf("%.2f\n", quantity * 1.50);
        break;
    }
    return 0;
}