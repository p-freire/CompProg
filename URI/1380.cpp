#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define tamMax 1510
#define tamMaxFileira 1000010

using namespace std;
int fib[tamMax]; // por que 1500? Here -> http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibmaths.html#fibmod

/*
    A ideia principal desse algoritmo é fazer uso dos períodos de Pisano, que garantem que uma determinada sequência de números mod n irá se repetir na sequência de Fibonacci
    No caso, como os bilhetes vão de 0 a 999, então é necessário ter um ciclo mod 1000. A sequência para esse caso é de 1500 números da sequência de Fibonacci
    Para identificar os ciclos (o que não é feito aqui), é necessário fazer o seguinte:
        - guardar os dois primeiros números da sequência de Fibonacci (no caso, 1 e 1)
        - ir calculando os números da sequência mod n até encontrar novamente o 1 e 1
        - encontrando de novo os dois 1's significa que a sequência entrou em ciclo...
        - basta subtrair 2 (para os dois 1's) da quantidade de números calculados até o momento e...
        - PROFIT!!

    Para facilitar, eis um exemplo para modulo 2:
    Fibonacci:
        1   1   2   3   5   8   ...
        1   1   0   1   1   0   ...
    Ou seja, o ciclo para mod 2 tem tamanho igual a 3 (1, 1, 0)!
*/

int converte(char *numero, int tam)
{
    int aux, soma, potencia;
    soma = 0;
    potencia = 1;
    while(tam >= 0)
    {
        aux = (int)numero[tam] - 48;
        soma += (aux * potencia) % 1500;
        soma = soma % 1500;
        potencia = (potencia * 10) % 1500;
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
        tmp = converte(fileira, strlen(fileira) - 1);
        if(fib[tmp] < 10)
            printf("00%d\n", fib[tmp]);
        else if(fib[tmp] < 100)
            printf("0%d\n", fib[tmp]);
        else
            printf("%d\n", fib[tmp]);
    }
    return 0;
}
