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
    A ideia principal desse algoritmo Ã© fazer uso dos perÃ­odos de Pisano, que garantem que uma determinada sequÃªncia de nÃºmeros mod n irÃ¡ se repetir na sequÃªncia de Fibonacci
    No caso, como os bilhetes vÃ£o de 0 a 999, entÃ£o Ã© necessÃ¡rio ter um ciclo mod 1000. A sequÃªncia para esse caso Ã© de 1500 nÃºmeros da sequÃªncia de Fibonacci
    Para identificar os ciclos (o que nÃ£o Ã© feito aqui), Ã© necessÃ¡rio fazer o seguinte:
        - guardar os dois primeiros nÃºmeros da sequÃªncia de Fibonacci (no caso, 1 e 1)
        - ir calculando os nÃºmeros da sequÃªncia mod n atÃ© encontrar novamente o 1 e 1
        - encontrando de novo os dois 1's significa que a sequÃªncia entrou em ciclo...
        - basta subtrair 2 (para os dois 1's) da quantidade de nÃºmeros calculados atÃ© o momento e...
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