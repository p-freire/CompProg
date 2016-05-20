#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define tamMax 1510
#define tamMaxFileira 10010

using namespace std;
int fib[tamMax];

int binToDec(char *numero, int tam)
{
    int aux, soma, potencia;
    soma = 0;
    potencia = 1;
    while(tam >= 0)
    {
        aux = (int)numero[tam] - 48;
        soma += (aux * potencia) % 1500;
        soma = soma % 1500;
        potencia = (potencia * 2) % 1500;
        tam--;
    }
    return soma;
}

void fibonacci(int n)
{
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 1;
        for (int i = 3; i < n; i++)
            fib[i] = (fib[i-1] + fib[i-2]) % 1000;
}

int main()
{
    char fileira[tamMaxFileira];
    int instancia, tmp;
    fibonacci(tamMax);
    scanf("%d", &instancia);

    while(instancia--)
    {
        scanf("%s", fileira);
        tmp = binToDec(fileira, strlen(fileira) - 1);
        if(fib[tmp] < 10)
            printf("00%d\n", fib[tmp]);
        else if(fib[tmp] < 100)
            printf("0%d\n", fib[tmp]);
        else
            printf("%d\n", fib[tmp]);
    }
    return 0;
}