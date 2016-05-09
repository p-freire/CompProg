#include <iostream>
#include <string.h>
#include <math.h>
#define tamMax 100100
unsigned long long int vetor[tamMax];
using namespace std;
 
int main()
{
    unsigned long long int soma, somaInicial, qtdeNumeros, qtdeInstancias;
    memset(vetor, 0, sizeof(vetor));
    soma = 0;
    somaInicial = 0;
 
    scanf("%llu", &qtdeInstancias);
 
    while(qtdeInstancias--)
    {
        scanf("%llu", &qtdeNumeros);
 
        for(int i = 1; i <= qtdeNumeros; i++)
        {
            scanf("%llu", &vetor[i]);
            vetor[i] = vetor[i]  % 1300031;
            somaInicial += vetor[i];
        }
 
        soma += (vetor[1] * somaInicial) % 1300031;
        for(int i = 2; i <= qtdeNumeros; i++)
        {
            somaInicial -= vetor[i - 1];
            soma += (vetor[i] * somaInicial) % 1300031;
            soma = soma % 1300031;
        }
 
        printf("%llu\n",soma);
        soma = 0;
        somaInicial = 0;
    }
    return 0;
}
 