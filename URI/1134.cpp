#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int option, alcool, gasolina, diesel;
    alcool = gasolina = diesel = 0;
    do
    {
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            ++alcool;
             break;
        case 2:
            ++gasolina;
            break;
        case 3:
            ++diesel;
            break;
        default:
            break;
        }

    }while(option != 4);
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\nGasolina: %d\nDiesel: %d\n", alcool, gasolina, diesel);
    return 0;
}
